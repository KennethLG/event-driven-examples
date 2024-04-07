const EventEmitter = require('events');

class GameEventEmitter extends EventEmitter {}
const gameEvents = new GameEventEmitter();


class VisualEffectsSystem {
  constructor() {
    gameEvents.on('weaponFired', this.showMuzzleFlash);
  }

  showMuzzleFlash() {
    console.log('Showing muzzle flash and smoke');
  }
}


class WeaponSystem {
  fireWeapon() {
    console.log('Weapon fired!');
    gameEvents.emit('weaponFired');
  }
}

// Initialize systems
const weaponSystem = new WeaponSystem();
const visualEffectsSystem = new VisualEffectsSystem();

// Simulate firing a weapon
weaponSystem.fireWeapon();
