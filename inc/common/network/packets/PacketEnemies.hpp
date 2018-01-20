//
// Created by guillobits on 17/01/18.
//

#ifndef     _PACKET_ENEMIES__HPP_
# define    _PACKET_ENEMIES__HPP_

# include <vector>
# include <boost/serialization/base_object.hpp>
# include "APacket.hpp"
# include "common/gameManager/Enemy.hpp"

namespace Network
{
    namespace Packet
    {
        class PacketEnemies : public APacket
        {
        private:
            friend class boost::serialization::access;
            std::vector<Enemy>      _enemies;

        public:
            PacketEnemies() : APacket(PACKET_ENEMIES) {}
            explicit PacketEnemies(const std::vector<Enemy> &enemies) : APacket(PACKET_ENEMIES), _enemies(enemies) {}

            std::vector<Enemy>  &getEnemies() { return this->_enemies; }
            void                setEnemies(const std::vector<Enemy> &enemies) { this->_enemies = enemies; }


            template <class Archive>
            void	serialize(Archive& ar, const unsigned int version)
            {
                ar & boost::serialization::base_object<APacket>(*this);
                ar & _enemies;
            }
        };
    }
}

#endif      /* !_PACKET_ENEMIES__HPP_! */