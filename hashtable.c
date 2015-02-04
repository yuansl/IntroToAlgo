
/* A structure of hash table */
struct h_node {
	int key;
	int collision;
};

struct hash_t {
	struct h_node *slots;
	int size;
};

bool is_prime(int m)
{
	int j;
	for (j = m / 2; j >= 2; j--)
		if (m % j == 0) 
			return false;
	return true;
}

int next_prime(int m)
{
	int j;
	for (j = m; ; j++)
		if (is_prime(j))
			break;
	return j;
}

struct hash_t *init_hash(int n)
{
	struct hash_t *ht;

	ht = malloc(sizeof(*ht));
	ht->size = next_prime(n);
	ht->slots = malloc(ht->size * sizeof(struct h_node));
	memset(ht->slots, 0, ht->size * sizeof(struct h_node));
	return ht;
}

int hash(struct hash_t *ht, int key)
{
	return key % ht->size;
}

int hash_search(struct hash_t *ht, int key)
{
	int i, j, k;

	k = hash(ht, key);
	for (i = 0; i < ht->size; i++) {
		j = (k + i) % ht->size;
		if (ht->slots[j].key == key)
			return j;
	}
	return -1;
}

int hash_insert(struct hash_t *ht, int key)
{
	int i, j, k;

	k = hash(ht, key);
	for (i = 0; i < ht->size; i++) {
		j = (k + i) % ht->size;
		if (ht->slots[j].collision == 0 ||
		    ht->slots[j].key == key) {
			ht->slots[j].key = key;
			ht->slots[j].collision++;
			return true;
		}
	}
	return false;
}

bool hash_delete(struct hash_t *ht, int key)
{
	int i, j, k;

	k = hash(ht, key);
	for (i = 0; i < ht->size; i++) {
		j = (k + i) % ht->size;
		if (ht->slots[j].key == key) {
			if (ht->slots[j].collision == 0)
				return false;
			ht->slots[j].collision--;
			return true;
		}
	}
	return false;
}
