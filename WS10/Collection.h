#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_

namespace sdds {
    template <typename T>                        // Template class for Collection
    class Collection {
        T* m_data = nullptr;                      // Pointer to the data array of type T
        int m_size = 0;                           // Size of the collection

    public:
        // Default constructor with an optional size parameter (default is 0)
        Collection(int size = 0);

        // Copy constructor
        Collection(const Collection<T>& CP);

        // Copy assignment operator
        Collection<T>& operator=(const Collection<T>& RO);

        // Get the size of the collection
        int size() const;

        // Resize the collection to a new size
        void resize(int newsize);

        // Access element at a specific index in the collection
        T& operator[](int index);

        // Add an element to the collection
        Collection<T>& add(const T& element);

        // Destructor to clean up memory
        ~Collection();
    };

    template <typename T>
    Collection<T>::Collection(int size) : m_size(size) {
        // Initialize the size of the collection and allocate memory for data
        if (m_size <= 0) m_size = 0;
        if (m_size > 0) m_data = new T[m_size];
    }

    template <typename T>
    Collection<T>::Collection(const Collection<T>& CP) {
        // Copy constructor
        operator=(CP);
    }

    template <typename T>
    Collection<T>& Collection<T>::operator=(const Collection<T>& RO) {
        // Copy assignment operator
        if (this != &RO) {
            delete[] m_data;
            m_data = new T[m_size = RO.m_size];
            for (int i = 0; i < m_size; i++) m_data[i] = RO.m_data[i];
        }
        return *this;
    }

    template <typename T>
    int Collection<T>::size() const {
        // Get the size of the collection
        return m_size;
    }

    template <typename T>
    void Collection<T>::resize(int newsize) {
        // Resize the collection to a new size
        int i;
        T* temp = nullptr;
        if (newsize < 0) newsize = 0;
        if (newsize > 0) {
            temp = new T[newsize];
            for (i = 0; i < m_size && i < newsize; i++) {
                temp[i] = m_data[i];
            }
        }
        delete[] m_data;
        m_data = temp;
        m_size = newsize;
    }

    template <typename T>
    T& Collection<T>::operator[](int index) {
        // Access element at a specific index in the collection
        if (index >= m_size) resize(index + 1);
        return m_data[index];
    }

    template <typename T>
    Collection<T>& Collection<T>::add(const T& element) {
        // Add an element to the collection
        (*this)[size()] = element;
        return *this;
    }

    template <typename T>
    Collection<T>::~Collection() {
        // Destructor to clean up memory
        delete[] m_data;
    }
}

#endif // !SDDS_COLLECTION_H_
