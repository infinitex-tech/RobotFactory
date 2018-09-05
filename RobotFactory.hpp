#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
#include <eosiolib/types.hpp>
#include <string>

namespace Factory {
    using namespace eosio;
    using std::string;

    /**
     * The RobotFactory class inherits the "contract" smart contract and use its constructor (using contract::contract)
    */
    class RobotFactory : public contract {
        using contract::contract;

        public:

            RobotFactory(account_name self):contract(self) {}

            //@abi table robot i64
            struct robot {
                uint64_t series_number;
                string model;
                string operating_system;
                string profession;
                string owner;
                uint32_t manufactured;

                uint64_t primary_key() const { return series_number; }

                EOSLIB_SERIALIZE(robot, (series_number)(model)(operating_system)(profession)(owner)(manufactured))
            };

            typedef multi_index<N(robot), robot> robotIndex;

            //@abi action
            void create(account_name account, robot newRobot);

            //@abi action
            void update(account_name account, uint64_t series_number, string operating_system);

            //@abi action
            void getbyid(uint64_t robotId);

            //@abi action
            void remove(account_name account, uint64_t robotId);
    };

    EOSIO_ABI(RobotFactory, (create)(update)(getbyid)(remove));
}
