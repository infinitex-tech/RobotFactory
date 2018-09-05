# Robot Factory - Live Demo


### Running local testnet:
```
nodeos -e -p eosio --plugin eosio::wallet_api_plugin --plugin eosio::chain_api_plugin --plugin eosio::history_api_plugin --contracts-console --verbose-http-errors
```

### Commands:

1. Creating a wallet

```sh
# cleos wallet create -n {wallet_name}

cleos wallet create -n factory
```

*Note: Don't forget to save your password*

2. Generating keys

```sh
cleos create key
```

*Note: Don't forget to save your generated keys*

3. Import the generated keys in the wallet

```sh
# OwnerKey = private_key_1
# ActiveKey = private_key_2

cleos wallet import --private-key={private_key_1} -n factory
cleos wallet import --private-key={private_key_2} -n factory
```

4. Import the eosio private key in the wallet

```sh
cleos wallet import --private-key=5KQwrPbwdL6PhXujxW37FSSQZ1JiwsST4cqQzDeyXtP79zkvFD3 -n factory
```

5. Creating new account

```sh
# cleos create account eosio {new_account_name} {public_OwnerKey} {public_ActiveKey}
# "eosio" is the name of the account who will create the new one

cleos create account eosio weyland {public_OwnerKey} {public_ActiveKey}
```

6. Creating the smart contract


7. Generating the WAST file
   
```sh
eosiocpp -o RobotFactory.wast RobotFactory.cpp
```

8. Generating the ABI file

```sh
eosiocpp -g RobotFactory.abi RobotFactory.cpp
```

9. Deploying the smart contract

```sh
# cleos set contract {account} {path_to_contract_folder} {path_to_.wast_file} {path_to_.abi_file}
cleos set contract weyland . RobotFactory.wast RobotFactory.abi
```

10. Creating new robot

```sh
# cleos push action {account} {action_name} '{data}' -p {account}
cleos push action weyland create '{"account":"weyland","newRobot":{"series_number":14001992,"model":"A330","operating_system":"DX42","profession":"engineer","owner":"","manufactured":0}}' -p weyland
```

11. Get robot by series number

```sh
cleos push action weyland getbyid '[14001992]' -p weyland
```

12. Update robot OS

```sh
cleos push action weyland update '["weyland",14001995,"X99A"]' -p weyland
```

13. Remove robot

```sh
cleos push action weyland remove '["weyland",14001995]' -p weyland
```

### Example data for robots:

| Series Number | Model |  OS  |  Profession  |
|:-------------:|:-----:|:----:|:------------:|
|    14001992   |  A330 | DX42 |   engineer   |
|    14001993   |  A720 | DX49 |  babysitter  |
|    14001994   |  U835 | D33R |    farmer    |
|    14001995   |  XS33 | DZ4S | neurosurgeon |
|    14001996   |  XS33 | X99A |    cashier   |
