#pragma once

#include <sc2api/sc2_api.h>
#include <vector>
#include <utility>

using namespace sc2;
using namespace std;
using DisplayType = Unit::DisplayType;
using Alliance = Unit::Alliance;
using CloakState = Unit::CloakState;

class UnitWrapper {
public:
    UnitWrapper(const Unit* u);

    void addTo(vector<UnitWrapper*>& list);

    void removePtrs();

    const Unit* unit;

    //! If the unit is shown on screen or not.
    const DisplayType& display_type;
    //! Relationship of the unit to this player.
    const Alliance& alliance;

    //! A unique identifier for the instance of a unit.
    const Tag& tag;
    //! An identifier of the type of unit.
    const UnitTypeID& unit_type;
    //! Which player owns a unit.
    const const int& owner;

    //! Position of the unit in the world.
    const Point3D& pos;
    //! Direction the unit faces in radians (1 radian == 57.296 degrees)
    const float& facing;
    //! Radius of the unit.
    const float& radius;
    //! Gives progress under construction. Range: [0.0, 1.0]. 1.0 == finished.
    const float& build_progress;

    //! If the unit is cloaked.
    const CloakState& cloak;

    //! Range of detector for detector units.
    const float& detect_range;
    //! Range of radar for units that are radar units.
    const float& radar_range;

    //! If the unit is in the current selection of the player.
    const bool& is_selected;
    //! Visible and within the camera frustum.
    const bool& is_on_screen;
    //! Detected by sensor tower.
    const bool& is_blip;

    // Not populated for snapshots

    //! Health of the unit. Not set for snapshots.
    const float& health;
    //! Max health for the unit. Not set for snapshots.
    const float& health_max;
    //! Shield of the unit. Not set for snapshots.
    const float& shield;
    //! Max shield of the unit. Not set for snapshots.
    const float& shield_max;
    //! Energy of the unit. Not set for snapshots.
    const float& energy;
    //! Max energy of the unit. Not set for snapshots.
    const float& energy_max;
    //! Amount of minerals if the unit is a mineral field. Not set for snapshots.
    const int& mineral_contents;
    //! Amount of vespene if the unit is a geyser. Not set for snapshots.
    const int& vespene_contents;
    //! If the unit is flying. Not set for snapshots.
    const bool& is_flying;
    //! If the unit is burrowed. Not set for snapshots.
    const bool& is_burrowed;
    //! If the unit is hallucination. Not set for snapshots.
    const bool& is_hallucination;
    //! Time remaining for a weapon on cooldown. Not set for snapshots.
    const float& weapon_cooldown;

    // Not populated for enemies/snapshots

    //! Orders on a unit. Only valid for this player's units.
    const std::vector<UnitOrder>& orders;
    //! Add-on like a tech lab or reactor. Only valid for this player's units.
    const Tag& add_on_tag;
    //! Passengers in this transport. Only valid for this player's units.
    const std::vector<PassengerUnit>& passengers;
    //! Number of cargo slots used in the transport. Only valid for this player's units.
    const int& cargo_space_taken;
    //! Number of cargo slots available for a transport. Only valid for this player's units.
    const int& cargo_space_max;
    //! Number of harvesters associated with a town hall (e.g., Command Center). Only valid for this player's units.
    const int& assigned_harvesters;
    //! Number of harvesters that can be assigned to a town hall (e.g., Command Center) or a geyser (e.g., Refinery).
    //! Only valid for this player's units.
    const int& ideal_harvesters;
    //! Target unit of a unit. Only valid for this player's units.
    const Tag& engaged_target_tag;
    //! Buffs on this unit. Only valid for this player's units.
    const std::vector<BuffID>& buffs;
    //! Whether the unit is powered by a pylon.
    const bool& is_powered;

    //! Whether the unit is alive or not.
    const bool& is_alive;
    //! The last time the unit was seen.
    const uint32_t& last_seen_game_loop;

    //! Level of weapon upgrades.
    const uint32_t& attack_upgrade_level;

    //! Level of armor upgrades.
    const int32_t& armor_upgrade_level;

    //! Level of shield upgrades.
    const int32_t& shield_upgrade_level;

    //! Whether the unit is building or not.
    const bool& is_building;

    //! Whether the unit construction/training completed.
    [[nodiscard]] bool IsBuildFinished() const;

private:
    vector<pair<vector<UnitWrapper*>*, UnitWrapper**>> vecPtrs;
};

