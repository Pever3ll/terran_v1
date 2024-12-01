#include <sc2api/sc2_api.h>

#include <iostream>

using namespace sc2;
using namespace std;

class Bot : public Agent {
public:
    //! Called when a game is started after a load. Fast restarting will not call this.
    virtual void OnGameFullStart() {
    }

    //! Called when a game is started or restarted.
    virtual void OnGameStart() {
        cout << "Hello world!" << endl;
    }

    //! Called when a game has ended.
    virtual void OnGameEnd() {
    }

    //! In non realtime games this function gets called after each step as indicated by step size.
    //! In realtime this function gets called as often as possible after request/responses are received from the game
    //! gathering observation state.
    virtual void OnStep() {
        std::cout << Observation()->GetGameLoop() << std::endl;
    }

    //! Called whenever one of the player's units has been destroyed.
    //!< \param unit The destroyed unit.
    virtual void OnUnitDestroyed(const Unit*) {
    }

    //!  Called when a neutral unit is created. For example, mineral fields observed for the first time
    //!< \param unit The observed unit.
    virtual void OnNeutralUnitCreated(const Unit*) {
    }

    //! Called when a Unit has been created by the player.
    //!< \param unit The created unit.
    virtual void OnUnitCreated(const Unit*) {
    }

    //! Called when a unit becomes idle, this will only occur as an event so will only be called when the unit becomes
    //! idle and not a second time. Being idle is defined by having orders in the previous step and not currently having
    //! orders or if it did not exist in the previous step and now does, a unit being created, for instance, will call
    //! both OnUnitCreated and OnUnitIdle if it does not have a rally set.
    //!< \param unit The idle unit.
    virtual void OnUnitIdle(const Unit* unit) final {
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
    virtual void OnUpgradeCompleted(UpgradeID) {
    }

    //! Called when the unit in the previous step had a build progress less than 1.0 but is greater than or equal to 1.0
    //! in
    // !the current step.
    //!< \param unit The constructed unit.
    virtual void OnBuildingConstructionComplete(const Unit*) {
    }

    //! Called when the unit in the current observation has lower health or shields than in the previous observation.
    //!< \param unit The damaged unit.
    //!< \param health The change in health (damage is positive)
    //!< \param shields The change in shields (damage is positive)
    virtual void OnUnitDamaged(const Unit*, float /*health*/, float /*shields*/) {
    }

    //! Called when a nydus is placed.
    virtual void OnNydusDetected() {
    }

    //! Called when a nuclear launch is detected.
    virtual void OnNuclearLaunchDetected() {
    }

    //! Called when an enemy unit enters vision from out of fog of war.
    //!< \param unit The unit entering vision.
    virtual void OnUnitEnterVision(const Unit*) {
    }

    //! Called for various errors the library can encounter. See ClientError enum for possible errors.
    virtual void OnError(const std::vector<ClientError>& /*client_errors*/,
                         const std::vector<std::string>& /*protocol_errors*/ = {}) {
    }
};

int main(int argc, char* argv[]) {
    Coordinator coordinator;
    coordinator.LoadSettings(argc, argv);

    Bot bot;
    coordinator.SetParticipants({
        CreateParticipant(Terran, &bot),
        CreateComputer(Zerg)
    });

    coordinator.LaunchStarcraft();
    coordinator.StartGame(kMapBelShirVestigeLE);

    while (coordinator.Update()) {

    }

    return 0;
}
