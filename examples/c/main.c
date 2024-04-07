#include <stdio.h>
#include <stdlib.h>

// Define a function pointer type for event callbacks
typedef void (*EventCallback)(void*);

// Simple structure for a single event listener
typedef struct {
    EventCallback callback;
    void* context;
} EventListener;

// Example event: weapon fired
#define MAX_LISTENERS 10
EventListener weaponFiredListeners[MAX_LISTENERS];
int weaponFiredCount = 0;

void subscribeToWeaponFired(EventCallback callback, void* context) {
    if (weaponFiredCount < MAX_LISTENERS) {
        weaponFiredListeners[weaponFiredCount++] = (EventListener){callback, context};
    }
}

void emitWeaponFired() {
    printf("Weapon fired!\n");
    for (int i = 0; i < weaponFiredCount; ++i) {
        weaponFiredListeners[i].callback(weaponFiredListeners[i].context);
    }
}

// Example callback function
void onWeaponFired(void* context) {
    printf("Showing muzzle flash and smoke\n");
}

int main() {
    subscribeToWeaponFired(onWeaponFired, NULL);
    emitWeaponFired();
    return 0;
}
