#include iostream
#include string

template typename T
class DizionarioEsteso {
private
    static const int TABLE_SIZE = 10;  Dimensione della tabella hash
    struct Entry {
        stdstring key;
        T value;
        bool isOccupied = false;  Indica se lo slot è occupato
    };

    Entry table[TABLE_SIZE];  Tabella hash

    int hashFunction(const stdstring& key) const {
        int hash = 0;
        for (char ch  key) {
           hash += static_castint(ch);
        }
        return hash % TABLE_SIZE;
    }

    int findSlot(int index, const stdstring& key) const {
         Linear probing cerca la prossima posizione libera
        while (table[index].isOccupied && table[index].key != key) {
            index = (index + 1) % TABLE_SIZE;   Scansione ciclica
        }
        return index;
    }

public
    void inserisci(const stdstring key, const T value) {
        int index = hashFunction(key);
        if (table[index].isOccupied) {
            stdcout  Collisione trovata per la chiave   key   all'indice   index  . Risoluzione della collisione.n;
            index = findSlot(index, key);   Trova la posizione libera
        }

        table[index].key = key;
        table[index].value = value;
        table[index].isOccupied = true;
        stdcout  Inserito   key   =   value   all'indice   index  n;
    }

    void cancella(const stdstring key) {
        int index = hashFunction(key);
        index = findSlot(index, key);   Trova la posizione corretta
        if (table[index].isOccupied && table[index].key == key) {
            table[index].isOccupied = false;
            stdcout  Eliminata   key   all'indice   index  n;
        } else {
            stdcout  Chiave non trovata per eliminazione!n;
        }
    }

    T recupera(const stdstring key) const {
        int index = hashFunction(key);
        index = findSlot(index, key);   Trova la posizione corretta
        if (table[index].isOccupied && table[index].key == key) {
            return table[index].value;
        }
        stdcout  Chiave non trovata per il recupero!n;
        return T();   Restituisce un valore di default
    }

    bool appartiene(const stdstring key) const {
        int index = hashFunction(key);
        index = findSlot(index, key);   Trova la posizione corretta
        if (table[index].isOccupied && table[index].key == key) {
            return true;
        }
        return false;
    }

    void stampa() const {
        for (int i = 0; i  TABLE_SIZE; ++i) {
            if (table[i].isOccupied) {
                stdcout  Indice   i     table[i].key   =   table[i].value  n;
            }
        }
    }
};
