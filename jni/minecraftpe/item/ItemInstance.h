#pragma once

#include <string>
#include <memory>
#include <chrono>
#include <ratio>

class Item;
class CompoundTag;
class Block;
class Color;
class Level;
class BlockEntity;
class BlockSource;
class Entity;
class Player;
class Mob;
class ItemUseCallback;
class BlockID;
class ItemEnchants;
class IDataInput;
class IDataOutput;

namespace Json {
    class Value;
};

class ItemInstance {
public:
    ItemInstance(ItemInstance const&);
    ItemInstance();
    ItemInstance(int, int, int);
    ItemInstance(Item const&, int);
    ItemInstance(Item const&, int, int);
    ItemInstance(Item const&);
    ItemInstance(int, int, int, CompoundTag const*);
    ItemInstance(Block const&, int);
    ItemInstance(Block const&);
    ItemInstance(Block const&, int, int);
    ItemInstance(Item const&, int, int, CompoundTag const*);
    ~ItemInstance();

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
    int /* UseAnimation */ getUseAnimation() const;
    bool isGlint() const;
    bool hasCustomHoverName() const;
    void* /*TODO*/ getIcon(int, bool) const;
    std::string getName() const;
    Color getColor() const;
    int getMaxDamage() const;
    int getDamageValue() const;
    void* getPickupPopPercentage() const;
    bool isDamaged() const;
    bool isStackedByData() const;
    void matches(ItemInstance const&) const;
    void setUserData(std::unique_ptr<CompoundTag, std::default_delete<CompoundTag> >);
    void setShowPickUp(bool);
    void setPickupTime(std::chrono::time_point<std::chrono::_V2::steady_clock, std::chrono::duration<long long, std::ratio<1ll, 1000000000ll> > >);
    void retrieveIDFromIDAux(int);
    void retrieveAuxValFromIDAux(int);
    void retrieveEnchantFromIDAux(int);
    int getIsValidPickupTime() const;
    bool isStackable() const;
    int getPickupTime() const;
    bool isDamageableItem() const;
    void* getIdAuxEnchanted() const;
    void matchesItem(ItemInstance const&) const;
    int getMaxStackSize() const;
    int getIdAux() const;
    bool isLiquidClipItem() const;
    void* getUserData() const;
    std::string const& getFormattedHovertext(Level&, bool) const;
    bool hasUserData() const;
    void* getEnchantsFromUserData() const;
    void addCustomUserData(BlockEntity&, BlockSource&);
    int getRawNameId() const;
    void addComponents(Json::Value const&, std::string&);
    int getDescriptionId() const;
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
    void hurtEnemy(Mob*, Mob*);
    void startCoolDown(Player*) const;
    float getDestroySpeed(Block const&) const;
    bool canDestroySpecial(Block const&) const;
    void toString() const;
    void use(Player&);
    void useOn(Entity&, int, int, int, signed char, float, float, float, ItemUseCallback*);
    void mineBlock(BlockID, int, int, int, Mob*);
    void setPickupTime();
    void componentsMatch(ItemInstance const&) const;
    bool hasSameUserData(ItemInstance const&) const;
    void saveEnchantsToUserData(ItemEnchants const&);
    void deserializeComponents(IDataInput&);
    std::string getCustomName() const;
    std::string getCategoryName() const;
    bool isMusicDiscItem() const;
    void serializeComponents(IDataOutput&) const;
    bool hasCompoundTextUserData() const;
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
    void _hasComponents() const;
    int getEnchantSlot() const;
    void _saveComponents(CompoundTag&) const;
    bool isEquivalentArmor(ItemInstance const&) const;
    void* getNetworkUserData() const;
    void* _getHoverFormattingPrefix() const;

    static void* EMPTY_ITEM;
    static std::string TAG_ENCHANTS;
    static std::string TAG_DISPLAY;
    static int MAX_STACK_SIZE;
    static std::string TAG_CAN_DESTROY;
    static std::string TAG_REPAIR_COST;
    static std::string TAG_CAN_PLACE_ON;
    static std::string TAG_DISPLAY_NAME;
    static std::string TAG_STORE_CAN_DESTROY;
    static std::string TAG_STORE_CAN_PLACE_ON;
    static std::string TAG_LORE;
};
