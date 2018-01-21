//
// Created by guillobits on 17/01/18.
//

#ifndef     _PACKET_PROJECTILES__HPP_
# define    _PACKET_PROJECTILES__HPP_

# include <vector>
# include <boost/serialization/base_object.hpp>
# include <boost/serialization/vector.hpp>
# include "APacket.hpp"
# include "common/gameManager/Projectile.hpp"

namespace Network
{
    namespace Packet
    {
        class PacketProjectiles : public APacket
        {
        private:
            friend class boost::serialization::access;
            std::vector<Projectile>     _projectiles;

        public:
            PacketProjectiles() : APacket(PACKET_PROJECTILES) {}
            explicit PacketProjectiles(const std::vector<Projectile> projectiles) : APacket(PACKET_PROJECTILES), _projectiles(projectiles) {}

            std::vector<Projectile>  &getProjectiles() { return this->_projectiles; }
            void                    setProjectiles(const std::vector<Projectile> projectiles) { this->_projectiles = projectiles; }

            template <class Archive>
            void	serialize(Archive& ar, const unsigned int version)
            {
                ar & boost::serialization::base_object<APacket>(*this);
                ar & _projectiles;
            }
        };
    }
}

#endif      /* !_PACKET_PROJECTILES__HPP_! */