//
// Created by thomas on 15/01/18.
//

#include "TimeManager.hpp"
#include "GameManager.hpp"

GameManager::GameManager(Network::Core::UdpConnection &socket) : _socket(socket)
{
}

GameManager::~GameManager()
{

}


void GameManager::update()
{
  TimeManager clock;
  TimeManager spwanRate;
  Network::Core::Endpoint ep("127.0.0.1", 4242);
  this->_projetcile.emplace_back(Projectile(Position2D(0, 0)));
  this->_projetcile.emplace_back(Projectile(Position2D(0, 10)));
  this->_projetcile.emplace_back(Projectile(Position2D(0, 30)));
  this->_projetcile.emplace_back(Projectile(Position2D(0, 50)));
  this->_projetcile.emplace_back(Projectile(Position2D(0, 80)));
  this->_projetcile.emplace_back(Projectile(Position2D(0, 90)));
  this->_projetcile.emplace_back(Projectile(Position2D(0, 120)));
  this->_projetcile.emplace_back(Projectile(Position2D(0, 150)));
  this->_projetcile.emplace_back(Projectile(Position2D(0, 170)));
  this->_projetcile.emplace_back(Projectile(Position2D(0, 190)));
  this->_projetcile.emplace_back(Projectile(Position2D(0, 200)));
  this->_projetcile.emplace_back(Projectile(Position2D(0, 300)));


  while (playerStillAlive()) //Todo Connexion rompu? Personnage tous mort ?
  {
    if (clock.getElapsedTime() > 1.0 / 60)
    {
      // Todo Send les pos de tout les trucs

      /*
       * if player fire
       * createProjectile(Player that fired)
       * */
      this->_socket.async_write("mdr", Network::Packet::PacketType::PACKET_PLAYER, ep,
			 [&](const boost::system::error_code &e, const long unsigned int&)
			 {
			   std::cout << "-- Packet has been sent" << std::endl;
			 });
      missileCollide();
      updateEntities();
      //dumpEnnemy();
      removeEntities();
      clock.restartTimer();
    }
    if (spwanRate.getElapsedTime() > 3.0)
    {
      spawnEnnemy();
      spwanRate.restartTimer();
    }
  }

}

void GameManager::createProjectile(Player &player)
{
  this->_projetcile.emplace_back(Projectile(player.getPosition()));
}

void GameManager::spawnEnnemy()
{
  this->_ennemy.emplace_back(Enemy());
}

void GameManager::addPlayer(Player &player)
{
  this->_player.push_back(player);
}

bool GameManager::playerStillAlive()
{
  for (auto it : this->_player)
  {
    if (it.getHp() > 0)
      return (true);
  }
  return (false);
}


void GameManager::updateEntities()
{
  for (auto &it : this->_ennemy)
    it.update();
  for (auto &it2 : this->_projetcile)
    it2.update();
}


void GameManager::removeEntities()
{
    for (auto it = this->_ennemy.begin(); it != this->_ennemy.end(); ++it) {
      if (it->getPosition().getX() < -100) {
	it = this->_ennemy.erase(it);
	it--;
      }
    }

  for (auto it = this->_projetcile.begin(); it != this->_projetcile.end(); ++it) {
    if (it->getPosition().getX() > 1700) {
      it = this->_projetcile.erase(it);
      it--;
    }
  }
}

void GameManager::dumpPlayer()
{
  for (auto it : this->_player)
  {
    std::cout << it.getId() << " " << it.getName() << " " << it.getPosition().getX() << " "<< it.getPosition().getY() << std::endl;
  }
}

void GameManager::dumpEnnemy()
{
  std::cout << "-------------------------" << std::endl;
  for (auto it : this->_ennemy)
  {
    std::cout << "This is an ennemy with id " << it.getId() << " " << it.getPosition().getX() << " "<< it.getPosition().getY() << std::endl;
  }
  std::cout << "--------------------------" << std::endl;
}

bool GameManager::missileCollide()
{
  for (auto it : this->_projetcile)
  {
    for (auto it2 : this->_ennemy)
    {
	if (it.getRectangle().intersects(it2.getRectangle())) {
	  std::cout << it.getId() << std::endl;
	  std::cout << it2.getId() << std::endl;
	  exit(0);
	  return (true);
	}
    }
  }
  return false;
}
