#pragma once

#include <string>
#include <memory>
#include <chrono>

class Item;
class CompoundTag;
class Block;
class UseAnimation;
class TextureUVCoordinateSet;
class Color;
class Level;
class ItemEnchants;
class BlockEntity;
class BlockSource;
class Entity;
class Player;
class Mob;
class ItemUseCallback;
class BlockID;
class Input;
class Output;

namespace Json
{
	class Value;
}

class ItemInstance
{
public:
	ItemInstance(Item const&, int, int, CompoundTag const*);
    ItemInstance(Item const&);
    ItemInstance(Item const&, int);
    ItemInstance(Item const&, int, int);
    ItemInstance(Block const&);
    ItemInstance(Block const&, int);
    ItemInstance(Block const&, int, int);
    ItemInstance(ItemInstance const&);
    ItemInstance(int, int, int);
    ItemInstance(int, int, int, CompoundTag const*);
    ItemInstance();
    ~ItemInstance();
public:
	std::string getHoverName() const;
    std::string getEffectName() const;
    bool isNull() const;
    void set(int);
    void operator=(ItemInstance const&);
    int getId() const;
    void setNull();
    int getAuxValue() const;
    bool isThrowable() const;
    void* getStrippedNetworkItem() const;
    void operator==(ItemInstance const&) const;
    void operator!=(ItemInstance const&) const;
    int getMaxUseDuration() const;
    bool isHorseArmorItem() const;
    bool isArmorItem() const;
    UseAnimation getUseAnimation() const;
    bool isGlint() const;
    bool hasCustomHoverName() const;
    TextureUVCoordinateSet const& getIcon(int, bool) const;
    std::string getName() const;
    Color getColor() const;
    int getMaxDamage() const;
    int getDamageValue() const;
    void* getPickupPopPercentage() const;
    bool isDamaged() const;
    bool isStackedB() const;
    bool matches(ItemInstance const&) const;
    void setUse(std::unique_ptr<CompoundTag,std::default_delete<CompoundTag> >);
    void setShowPickUp(bool);
    void setPickupTime(std::chrono::time_point<std::chrono::_V2::steady_clock,std::chrono::duration<long long,std::ratio<1ll, 00ll> > >);
    void retrieveIDFromIDAux(int);
    void retrieveAuxValFromIDAux(int);
    void retrieveEnchantFromIDAux(int);
    int getIsValidPickupTime() const;
    bool isStackable() const;
    int getPickupTime() const;
    bool isDamageableItem() const;
    int getIdAuxEnchanted() const;
    bool matchesItem(ItemInstance const&) const;
    int getMaxStackSize() const;
    int getIdAux() const;
    bool isLiquidClipItem() const;
    void* getUse() const;
    std::string getFormattedHovertext(Level&, bool) const;
    bool hasUse() const;
    ItemEnchants& getEnchantsFromUse() const;
    void addCustomUse(BlockEntity&, BlockSource&);
    int getRawNameId() const;
    void addComponents(Json::Value const&,std::string&);
    void clone() const;
    void remove(int);
    void fromTag(CompoundTag const&);
    bool isStackable(ItemInstance const&) const;
    void save() const;
    bool isWearableItem() const;
    bool isPotionItem() const;
    void add(int);
    bool isEnchanted() const;
    int getEnchantValue() const;
    bool isOffhandItem() const;
    void setAuxValue(short);
    void setCustomName(std::string const&);
    void setRepairCost(int);
    void resetHoverName();
    bool isEnchantingBook() const;
    int getBaseRepairCost() const;
    bool wasJustBrewed() const;
    void sameItemAndAux(ItemInstance const&) const;
    void inventoryTick(Level&, Entity&, int, bool);
    void refreshedInContainer(Level&);
    void hurtAndBreak(int, Entity*);
    void load(CompoundTag const&);
    int getAttackDamage() const;
    void releaseUsing(Player*, int);
    void useTimeDepleted(Level*, Player*);
    void hurtEnemy(Mob*,Mob*);
    void startCoolDown(Player*) const;
    float getDestroySpeed(Block const&) const;
    bool canDestroySpecial(Block const&) const;
    std::string toString() const;
    void use(Player&);
    void useOn(Entity&, int, int, int, signed char, float, float, float, ItemUseCallback*);
    void mineBlock(BlockID, int, int, int,Mob*);
    void setPickupTime();
    void componentsMatch(ItemInstance const&) const;
    void hasSameUse(ItemInstance const&) const;
    void saveEnchantsToUse(ItemEnchants const&);
    void deserializeComponents(Input&);
    std::string getCustomName() const;
    std::string getCategoryName() const;
    bool isMusicDiscItem() const;
    void serializeComponents(Output&) const;
    bool hasCompoundTextUse() const;
    void setJustBrewed(bool);
    void _initComponents();
    void _loadComponents(CompoundTag const&);
    void updateComponent(std::string const&, Json::Value const&);
    void _cloneComponents(ItemInstance const&);
    bool isValidComponent(std::string const&);
    void _updateCompareHashes();
    void init(int, int, int);
    void snap(Player*);
    void _setItem(int);
    void useAsFuel();
    bool canDestroy(Block const*) const;
    bool canPlaceOn(Block const*) const;
    bool isFullStack() const;
    bool hasComponent(std::string const&) const;
    bool _hasComponents() const;
    int getEnchantSlot() const;
    void _saveComponents(CompoundTag&) const;
    int getDescriptionId() const;
    bool isEquivalentArmor(ItemInstance const&) const;
    void* getNetworkUse() const;
    std::string _getHoverFormattingPrefix() const;
public:
	static ItemInstance* EMPTY_ITEM;
	static std::string TAG_ENCHANTS;
	static std::string TAG_DISPLAY;
	static std::string MAX_STACK_SIZE;
    static std::string TAG_CAN_DESTROY;
    static std::string TAG_REPAIR_COST;
    static std::string TAG_CAN_PLACE_ON;
    static std::string TAG_DISPLAY_NAME;
    static std::string TAG_STORE_CAN_DESTROY;
    static std::string TAG_STORE_CAN_PLACE_ON;
    static std::string TAG_LORE;
    
};