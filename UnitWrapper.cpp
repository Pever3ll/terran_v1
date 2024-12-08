#include "UnitWrapper.h"

UnitWrapper::UnitWrapper(const Unit* u)
    : unit(u),
      display_type(u->display_type),
      alliance(u->alliance),
      tag(u->tag),
      unit_type(u->unit_type),
      owner(u->owner),
      pos(u->pos),
      facing(u->facing),
      radius(u->radius),
      build_progress(u->build_progress),
      cloak(u->cloak),
      detect_range(u->detect_range),
      radar_range(u->radar_range),
      is_selected(u->is_selected),
      is_on_screen(u->is_on_screen),
      is_blip(u->is_blip),
      health(u->health),
      health_max(u->health_max),
      shield(u->shield),
      shield_max(u->shield_max),
      energy(u->energy),
      energy_max(u->energy_max),
      mineral_contents(u->mineral_contents),
      vespene_contents(u->vespene_contents),
      is_flying(u->is_flying),
      is_burrowed(u->is_burrowed),
      is_hallucination(u->is_hallucination),
      weapon_cooldown(u->weapon_cooldown),
      orders(u->orders),
      add_on_tag(u->add_on_tag),
      passengers(u->passengers),
      cargo_space_taken(u->cargo_space_taken),
      cargo_space_max(u->cargo_space_max),
      assigned_harvesters(u->assigned_harvesters),
      ideal_harvesters(u->ideal_harvesters),
      engaged_target_tag(u->engaged_target_tag),
      buffs(u->buffs),
      is_powered(u->is_powered),
      is_alive(u->is_alive),
      last_seen_game_loop(u->last_seen_game_loop),
      attack_upgrade_level(u->attack_upgrade_level),
      armor_upgrade_level(u->armor_upgrade_level),
      shield_upgrade_level(u->shield_upgrade_level),
      is_building(u->is_building) {
}

void UnitWrapper::addTo(vector<UnitWrapper*>& list) {
    list.push_back(this);
    vecPtrs.push_back(make_pair(&list, &list.back()));
}

void UnitWrapper::removePtrs() {
    for (auto vec : vecPtrs) {
        iter_swap(&vec.first->back(), vec.second);
        vec.first->pop_back();
    }
}

bool UnitWrapper::IsBuildFinished() const {
    return build_progress >= 1.0F;
}