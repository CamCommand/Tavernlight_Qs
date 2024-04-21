Q4
void Game::addItemToPlayer(const std::string& recipient, uint16_t itemId)

{

    Player* player = g_game.getPlayerByName(recipient);

    if (!player) {

        player = new Player(nullptr);

                // if the player already exists than the above is never freed

        if (!IOLoginData::loadPlayerByName(player, recipient)) {

            delete player; 

                    // Free memory if loading fails

            return;

        }

    }

 

    Item* item = Item::CreateItem(itemId);

    if (!item) {

        delete player; 

                // Free memory if item creation fails

        return;

    }

 

    g_game.internalAddItem(player->getInbox(), item, INDEX_WHEREEVER, FLAG_NOLIMIT);

 

    if (player->isOffline()) {

        IOLoginData::savePlayer(player);

    } else {

        delete player; 

                // Free memory if player is online (and maybe add another parameter if some form of loading is happening)

    }

}