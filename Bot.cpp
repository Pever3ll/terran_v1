#include "Bot.hpp"

//! Called when a game is started after a load. Fast restarting will not call this.
void Bot::OnGameFullStart() {
}

//! Called when a game is started or restarted.
void Bot::OnGameStart() {
    cout << "Hello world!" << endl;
}

//! Called when a game has ended.
void Bot::OnGameEnd() {
}

//! In non realtime games this function gets called after each step as indicated by step size.
//! In realtime this function gets called as often as possible after request/responses are received from the game
//! gathering observation state.
void Bot::OnStep() {
    cout << Observation()->GetGameLoop() << std::endl;
}

//! Called whenever one of the player's units has been destroyed.
//!< \param unit The destroyed unit.
void Bot::OnUnitDestroyed(const Unit*) {
}

//!  Called when a neutral unit is created. For example, mineral fields observed for the first time
//!< \param unit The observed unit.
void Bot::OnNeutralUnitCreated(const Unit*) {
}

//! Called when a Unit has been created by the player.
//!< \param unit The created unit.
void Bot::OnUnitCreated(const Unit*) {
}

//! Called when a unit becomes idle, this will only occur as an event so will only be called when the unit becomes
//! idle and not a second time. Being idle is defined by having orders in the previous step and not currently having
//! orders or if it did not exist in the previous step and now does, a unit being created, for instance, will call
//! both OnUnitCreated and OnUnitIdle if it does not have a rally set.
//!< \param unit The idle unit.
void Bot::OnUnitIdle(const Unit* unit) {
    switch (unit->unit_type.ToType()) {
    case UNIT_TYPEID::TERRAN_COMMANDCENTER: {
        Actions()->UnitCommand(unit, ABILITY_ID::TRAIN_SCV);
        break;
    }
    default:
        break;
    }
}

//! Called when an upgrade is finished, warp gate, ground weapons, baneling speed, etc.
//!< \param upgrade The completed upgrade.
void Bot::OnUpgradeCompleted(UpgradeID) {
}

//! Called when the unit in the previous step had a build progress less than 1.0 but is greater than or equal to 1.0
//! in
// !the current step.
//!< \param unit The constructed unit.
void Bot::OnBuildingConstructionComplete(const Unit*) {
}

//! Called when the unit in the current observation has lower health or shields than in the previous observation.
//!< \param unit The damaged unit.
//!< \param health The change in health (damage is positive)
//!< \param shields The change in shields (damage is positive)
void Bot::OnUnitDamaged(const Unit*, float health, float shield) {
}

//! Called when a nydus is placed.
void Bot::OnNydusDetected() {
}

//! Called when a nuclear launch is detected.
void Bot::OnNuclearLaunchDetected() {
}

//! Called when an enemy unit enters vision from out of fog of war.
//!< \param unit The unit entering vision.
void Bot::OnUnitEnterVision(const Unit*) {
}

//! Called for various errors the library can encounter. See ClientError enum for possible errors.
void Bot::OnError(const std::vector<ClientError>& client_errors,
    const std::vector<std::string> & protocol_errors = {}) {
}
