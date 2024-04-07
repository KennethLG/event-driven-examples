#include <iostream>
#include <vector>
#include <functional>

class EventManager {
public:
    void subscribe(std::function<void()> listener) {
        listeners.push_back(listener);
    }

    void emit() {
        for (auto& listener : listeners) {
            listener();
        }
    }

private:
    std::vector<std::function<void()>> listeners;
};

class WeaponSystem {
public:
    void fireWeapon() {
        std::cout << "Weapon fired!" << std::endl;
        onFire();
    }

    EventManager onFire;
};

class VisualEffectsSystem {
public:
    void onWeaponFired() {
        std::cout << "Showing muzzle flash and smoke" << std::endl;
    }
};

int main() {
    WeaponSystem weaponSystem;
    VisualEffectsSystem visualEffectsSystem;

    weaponSystem.onFire.subscribe([&]() { visualEffectsSystem.onWeaponFired(); });

    weaponSystem.fireWeapon();
}
