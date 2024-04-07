class EventManager:
    def __init__(self):
        self.listeners = {}

    def subscribe(self, event_type, listener):
        if event_type not in self.listeners:
            self.listeners[event_type] = []
        self.listeners[event_type].append(listener)

    def emit(self, event_type, data=None):
        for listener in self.listeners.get(event_type, []):
            listener(data)

class WeaponSystem:
    def __init__(self, event_manager):
        self.event_manager = event_manager

    def fire_weapon(self):
        print("Weapon fired!")
        self.event_manager.emit('weapon_fired')

class VisualEffectsSystem:
    def __init__(self, event_manager):
        event_manager.subscribe('weapon_fired', self.show_muzzle_flash)

    def show_muzzle_flash(self, data):
        print("Showing muzzle flash and smoke")

if __name__ == "__main__":
    event_manager = EventManager()
    weapon_system = WeaponSystem(event_manager)
    visual_effects_system = VisualEffectsSystem(event_manager)

    weapon_system.fire_weapon()
