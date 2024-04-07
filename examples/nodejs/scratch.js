class EventManager {
  constructor() {
    this.listeners = {};
  }

  // Subscribe to an event
  on(eventType, listener) {
    if (!this.listeners[eventType]) {
      this.listeners[eventType] = [];
    }
    this.listeners[eventType].push(listener);
  }

  // Publish an event
  emit(eventType, ...args) {
    if (this.listeners[eventType]) {
      for (const listener of this.listeners[eventType]) {
        listener(...args);
      }
    }
  }
}

// Initializing the Event Manager
const eventManager = new EventManager();

class VisualEffectsSystem {
  constructor() {
    eventManager.on('weaponFired', this.showMuzzleFlash);
  }

  showMuzzleFlash() {
    console.log('Showing muzzle flash and smoke');
  }
}

class WeaponSystem {
  fireWeapon() {
    console.log('Weapon fired!');
    eventManager.emit('weaponFired');
  }
}

// Initialize systems
const weaponSystem = new WeaponSystem();
const visualEffectsSystem = new VisualEffectsSystem();

// Simulate firing a weapon
weaponSystem.fireWeapon();
