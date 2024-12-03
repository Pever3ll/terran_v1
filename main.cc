#include <sc2api/sc2_api.h>

#include <iostream>

using namespace sc2;
using namespace std;

#include "Bot.hpp"

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
