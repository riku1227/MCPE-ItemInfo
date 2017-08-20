#include <jni.h>
#include <dlfcn.h>
#include <string>
#include <sstream>
#include <android/log.h>
#include "substrate.h"

#include "minecraftpe/client/gui/GuiData.h"
#include "minecraftpe/item/ItemInstance.h"
#include "minecraftpe/entity/Player.h"

Player* player = nullptr;

std::string itos(int num)
{
    std::stringstream ss;
    ss<<num;
    std::string str = ss.str();
    return str;
}

void (*_Player_normalTick)(Player *);
void Player_normalTick(Player * self)
{
    _Player_normalTick(self);
    player = self;
}

void (*_GuiData_tick)(GuiData *);
void GuiData_tick(GuiData * self)
{
    _GuiData_tick(self);
    ItemInstance* item = player -> getSelectedItem();
    self -> showTipMessage(
    "ID:"+itos(item->getId())+" Data:"+itos(item->getAuxValue())+" Name:"+item->getName()+
    "\nCategoryName:"+item->getCategoryName()+"\n"+
    "EnchantValue:"+itos(item->getEnchantValue())+" EnchantSlot:"+itos(item->getEnchantSlot())+"\n"+
    "MaxDamage:"+itos(item->getMaxDamage())+" AttackDamage:"+itos(item->getAttackDamage()));
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
	MSHookFunction((void*)&GuiData::tick,(void*)&GuiData_tick,(void**)&_GuiData_tick);
    MSHookFunction((void*)&Player::normalTick,(void*)&Player_normalTick,(void**)&_Player_normalTick);
	return JNI_VERSION_1_2;
}