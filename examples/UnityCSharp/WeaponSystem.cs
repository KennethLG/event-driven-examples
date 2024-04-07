using UnityEngine;
using UnityEngine.Events;

public class WeaponSystem : MonoBehaviour
{
    // UnityEvent to be invoked when the weapon is fired
    public UnityEvent onFire;

    void Update()
    {
        // Check for the fire command (e.g., pressing the spacebar)
        if (Input.GetKeyDown(KeyCode.Space))
        {
            Debug.Log("Weapon Fired!");
            onFire.Invoke(); // Invoke the event
        }
    }
}
