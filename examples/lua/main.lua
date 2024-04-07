EventManager = {}
EventManager.__index = EventManager

function EventManager.new()
    return setmetatable({listeners = {}}, EventManager)
end

function EventManager:subscribe(eventType, listener)
    if not self.listeners[eventType] then
        self.listeners[eventType] = {}
    end
    table.insert(self.listeners[eventType], listener)
end

function EventManager:emit(eventType, data)
    for _, listener in ipairs(self.listeners[eventType] or {}) do
        listener(data)
    end
end

WeaponSystem = {}
WeaponSystem.__index = WeaponSystem

function WeaponSystem.new(eventManager)
    return setmetatable({eventManager = eventManager}, WeaponSystem)
end

function WeaponSystem:fireWeapon()
    print("Weapon fired!")
    self.eventManager:emit("weapon_fired")
end

VisualEffectsSystem = {}
VisualEffectsSystem.__index = VisualEffectsSystem

function VisualEffectsSystem.new(eventManager)
    local self = setmetatable({}, VisualEffectsSystem)
    eventManager:subscribe("weapon_fired", function(data) self:showMuzzleFlash(data) end)
    return self
end

function VisualEffectsSystem:showMuzzleFlash(data)
    print("Showing muzzle flash and smoke")
end

local eventManager = EventManager.new()
local weaponSystem = WeaponSystem.new(eventManager)
local visualEffectsSystem = VisualEffectsSystem.new(eventManager)

weaponSystem:fireWeapon()
