import java.util.*;

public class LFUCache {
	private final int capacity;
	private int minFreq;
	private final Map<Integer, Integer> keyToVal;
	private final Map<Integer, Integer> keyToFreq;
	private final Map<Integer, LinkedHashSet<Integer>> freqToKeys;

	public LFUCache(int capacity) {
		this.capacity = capacity;
		this.minFreq = 0;
		this.keyToVal = new HashMap<>();
		this.keyToFreq = new HashMap<>();
		this.freqToKeys = new HashMap<>();
	}

	public int get(int key) {
		if (!keyToVal.containsKey(key)) {
			return -1;
		}

		// Increase frequency
		int oldFreq = keyToFreq.get(key);
		int newFreq = oldFreq + 1;
		keyToFreq.put(key, newFreq);

		// Update frequency map
		freqToKeys.get(oldFreq).remove(key);
		freqToKeys.computeIfAbsent(newFreq, k -> new LinkedHashSet<>()).add(key);

		// If the previous minFreq bucket is empty, update minFreq
		if (freqToKeys.get(oldFreq).isEmpty()) {
			freqToKeys.remove(oldFreq);
			if (minFreq == oldFreq) {
				minFreq++;
			}
		}

		return keyToVal.get(key);
	}

	public void put(int key, int value) {
		if (capacity == 0) {
			return;
		}

		if (keyToVal.containsKey(key)) {
			// Update existing key's value and increase the frequency
			keyToVal.put(key, value);
			get(key);
			return;
		}

		// Insert new key
		if (keyToVal.size() >= capacity) {
			// Evict LFU: least frequently used item
			int lfuKey = freqToKeys.get(minFreq).iterator().next();
			freqToKeys.get(minFreq).remove(lfuKey);
			if (freqToKeys.get(minFreq).isEmpty()) {
				freqToKeys.remove(minFreq);
			}
			keyToVal.remove(lfuKey);
			keyToFreq.remove(lfuKey);
		}

		// Insert new key with initial frequency
		keyToVal.put(key, value);
		keyToFreq.put(key, 1);
		freqToKeys.computeIfAbsent(1, k -> new LinkedHashSet<>()).add(key);
		minFreq = 1;
	}

	// public static void main(String[] args) {
	//	 LFUCache cache = new LFUCache(2);
	//	 cache.put(1, 1);
	//	 cache.put(2, 2);
	//	 System.out.println(cache.get(1)); // returns 1
	//	 cache.put(3, 3); // evicts key 2
	//	 System.out.println(cache.get(2)); // returns -1 (not found)
	//	 System.out.println(cache.get(3)); // returns 3
	//	 cache.put(4, 4); // evicts key 1
	//	 System.out.println(cache.get(1)); // returns -1 (not found)
	//	 System.out.println(cache.get(3)); // returns 3
	//	 System.out.println(cache.get(4)); // returns 4
	// }
}
