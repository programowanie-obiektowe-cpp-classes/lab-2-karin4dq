#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    Resource* resource;

public:
    ResourceManager()
    {
        resource = new Resource();
    }

    ~ResourceManager()
    {
        delete resource;
    }

// konstruktor kopiujący
// other to referencja_do_obiektu_z_ktorego_kopiuje_dane
    ResourceManager(const ResourceManager& other)
    {
        resource = new Resource(*other.resource);
    }

// kopiujący operator przypisania
    ResourceManager& operator=(const ResourceManager& other )
    {
        if (this != &other) //ochrona przed samoprzypisaniem
        {
        // zwolnienie dotychczasowych zasobów
        // skopiowanie zasobów z other
            Resource* nowy_zasob = new Resource(*other.resource);
            delete resource;
            resource = nowy_zasob;
        
        }
        return *this;
    }

    double get() const
    {
        return (*resource).get();
    }
    
};
