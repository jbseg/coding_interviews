/*Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
*/

class Random {
    private:

    public:

	Random(){
	}
    

	void insert(int val){ // O(1)
    // check if in mapping
    if (vals.find(val) != vals.end()) return;

    // if not add val to linkedlist
    vec.push_back(val);
    vals.insert(val);
    val_to_ind[val] = vec.size();
    

	}

	bool remove(int val){ // O(1)

        // first check if val in data structure
        // if not return false
        if (vals.find(val) == vals.end()) return false;
        
        // if in stuct
        int ind = val_to_ind[val];
        swap(vec[ind], vec.back());
        vec.pop_back();
        val_to_ind.erase(val);
        vals.erase(val);
	}

	// use randrange(list) O(1) [1,4,3] sz--   [1,4,3,5]
	int getRandom(){ // O(1) 
        if (!vec.size()) return -1;

        int ran = randrange(vec.size());

        return ran;
	}
}

// Random r;
// r.insert(1);
// r.insert(2);
// r.getRandom()... 1 or 2
// r.remove(1)
// r.getRandom()... 2

// error checking: insert(already_existing_val) -> nothing happend
// remove(val_not_in_struct) -> 
// val type: int


// set<int> vals;
// unordered_map <val, ind_val> val_to_ind;
// vec<val>: vec.pop() O(1)



// Take Aways
// dict+linkedlist and dict+vector are both powerful data structures
// dict+linkedlist is better if you care about the order of the values
// dict+vector is better if you want a contiguous data structure of the values. 
// I feel like you would rarely have a need for this feature... except this problem ;)