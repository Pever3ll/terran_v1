#pragma once

#include <iostream>
#include <vector>
#include <sc2api/sc2_api.h>
#include <unordered_map>

#include "UnitWrapper.h"
#include "SCV.h"

using namespace sc2;
using namespace std;


class Bot : public Agent {
private:
    unordered_map<int, vector<UnitWrapper*>> my_units;
    vector<UnitWrapper*> vec;

public:
    virtual void OnGameFullStart();
    virtual void OnGameStart();
    virtual void OnGameEnd();
    virtual void OnStep();
    virtual void OnUnitDestroyed(const Unit*);
    virtual void OnNeutralUnitCreated(const Unit*);
    virtual void OnUnitCreated(const Unit* unit);
    virtual void OnUnitIdle(const Unit* unit) final;
    virtual void OnUpgradeCompleted(UpgradeID);
    virtual void OnBuildingConstructionComplete(const Unit*);
    virtual void OnUnitDamaged(const Unit*, float health, float shield);
    virtual void OnNydusDetected();
    virtual void OnNuclearLaunchDetected();
    virtual void OnUnitEnterVision(const Unit*);
    virtual void OnError(const std::vector<ClientError>& client_errors,
                         const std::vector<std::string>& protocol_errors);
};

UnitWrapper* createUnit(const Unit* u, UNIT_TYPEID type);