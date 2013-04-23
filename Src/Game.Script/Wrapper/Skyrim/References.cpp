#include "Stdafx.h"
#pragma unmanaged
#include <FreeScript/References.hpp>
#include <common/skyscript.h>
#pragma managed

#include "References.h"

using namespace System;
using namespace Game;


Skyrim::TESObjectREFR::TESObjectREFR(void* ptr) : Skyrim::TESForm(ptr)
{

}

Skyrim::TESObjectREFR::~TESObjectREFR()
{

}

Skyrim::TESForm^ Skyrim::TESObjectREFR::BaseForm::get()
{
	return gcnew Skyrim::TESForm(((FreeScript::TESObjectREFR*)NativeHandle)->baseForm);
}

Microsoft::Xna::Framework::Vector3 Skyrim::TESObjectREFR::Position::get()
{
	Microsoft::Xna::Framework::Vector3 vec;
	vec.X = ((FreeScript::TESObjectREFR*)ptr)->pos.X;
	vec.Y = ((FreeScript::TESObjectREFR*)ptr)->pos.Y;
	vec.Z = ((FreeScript::TESObjectREFR*)ptr)->pos.Z;
	return vec;
}

void Skyrim::TESObjectREFR::Position::set(Microsoft::Xna::Framework::Vector3 vec)
{
	((FreeScript::TESObjectREFR*)ptr)->pos.X = vec.X;
	((FreeScript::TESObjectREFR*)ptr)->pos.Y = vec.Y;
	((FreeScript::TESObjectREFR*)ptr)->pos.Z = vec.Z;
}

Microsoft::Xna::Framework::Vector3 Skyrim::TESObjectREFR::Rotation::get()
{
	Microsoft::Xna::Framework::Vector3 vec;
	vec.X = ((FreeScript::TESObjectREFR*)ptr)->rot.X;
	vec.Y = ((FreeScript::TESObjectREFR*)ptr)->rot.Y;
	vec.Z = ((FreeScript::TESObjectREFR*)ptr)->rot.Z;
	return vec;
}

void Skyrim::TESObjectREFR::Rotation::set(Microsoft::Xna::Framework::Vector3 vec)
{
	((FreeScript::TESObjectREFR*)ptr)->rot.X = vec.X;
	((FreeScript::TESObjectREFR*)ptr)->rot.Y = vec.Y;
	((FreeScript::TESObjectREFR*)ptr)->rot.Z = vec.Z;
}


Skyrim::Actor::Actor(void* ptr) : Skyrim::TESObjectREFR(ptr)
{

}

Skyrim::Actor::~Actor()
{

}

void Skyrim::Actor::QueueNiNodeUpdate()
{
	FreeScript::QueueNiNodeUpdate((FreeScript::Actor*)NativeHandle);
}

void Skyrim::Actor::UnequipAll()
{
	SActor::UnequipAll((FreeScript::Actor*)NativeHandle);
}

Skyrim::TESNPC^ Skyrim::Actor::BaseNpc::get()
{
	return gcnew Skyrim::TESNPC(FreeScript::ActorHelper((FreeScript::Actor*)NativeHandle).GetNpc());
}

bool Skyrim::Actor::Dead::get()
{
	return SActor::IsDead((FreeScript::Actor*)NativeHandle);
}

System::UInt32 Skyrim::Actor::Level::get()
{
	return SActor::GetLevel((FreeScript::Actor*)NativeHandle);
}

Skyrim::TESForm^ Skyrim::Actor::GetWornForm(System::UInt32 id)
{
	if(id > 14)
		throw gcnew Exception("The worn forms are in the following range [0, 14]");
	return gcnew Skyrim::TESForm((void*)FreeScript::GetWornForm((FreeScript::Actor*)NativeHandle, 1 << id));
}

void Skyrim::Actor::EquipItem(Skyrim::TESForm^ form)
{
	::ObjectReference::AddItem(rtti_cast(ptr, Actor, TESObjectREFR), (FreeScript::TESForm*)form->NativeHandle, 1, true);
	SActor::EquipItem((FreeScript::Actor*)ptr, (FreeScript::TESForm*)form->NativeHandle, true, false);
}