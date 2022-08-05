#define NULL 0
#define SIZE (65536)

typedef unsigned char *string;
typedef unsigned int uint;

int stringCompare(string a, string b) {
  while (*a != 0xFF && *b != 0xFF && *a == *b) {
    a++;
    b++;
  }

  return *a == *b;
}

uint hashCode(string key) {
  uint hashval;

  for (hashval = 0; *key != 0xFF; key++) {
    hashval = *key + 31 * hashval;
  }

  return hashval % SIZE;
}

string search(string hashArray[], string key) {
  uint hashIndex = hashCode(key);
  int count = 0;

  while (hashArray[hashIndex] != NULL) {
    if (stringCompare(hashArray[hashIndex], key)) {
      return hashArray[hashIndex];
    }

    hashIndex = (hashIndex + 1) % SIZE;

    count++;
    if (count == 16) break;
  }

  return NULL; // return place to insert?
}

void insert(string hashArray[], string key) {
  uint hashIndex = hashCode(key);
  int count = 0;

  while (hashArray[hashIndex] != NULL) {
    hashIndex = (hashIndex + 1) % SIZE;
    
    count++;
    if (count == 16) break;
  }

  hashArray[hashIndex] = key;
}


int compact(int strings[], int len, string source, int strings2[], string target, string hashArray[]) {
  string end = target;
  for (int i = 0; i < len; i += 1) {
    string match = search(hashArray, source + strings[i]);
    if (match) {
      strings2[i] = match - target;
    } else {
      string src = source + strings[i];
      strings2[i] = end - target;
      while (*src != 0xFF) {
        *end = *src;
        src += 1;
        end += 1;
      }

      *end = 0xFF;
      end += 1;
      insert(hashArray, target + strings2[i]);
    }
  }

  return end - target;
}
