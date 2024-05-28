#ifndef UNTITLED_PERSON_H
#define UNTITLED_PERSON_H
class PersonBase{
private:
    char* name{};
    char* egn{};
    char* address{};

public:
    PersonBase();
    ~PersonBase();

    void set_name(const char* name_new);
    void set_egn(const char* egn_new);
    void set_address(const char* address_new);

    const char* get_name() const;
    const char* get_egn() const;
    const char* get_address() const;

    virtual void printAll();

};

#endif 


#ifndef UNTITLED_PERSONESTATES_H
#define UNTITLED_PERSONESTATES_H
class PersonEstates: public PersonBase{
private:
    char** addresses;
    int numAddresses;

public:
    PersonEstates(const char* name, const char* egn, const char* address, int numAddresses, const char** estateAddresses);
    ~PersonEstates();

    void set_numAddresses(int num);
    int get_numAddresses() const;

    void set_estateAddresses(char** estateAddresses);
    char** get_estateAddresses() const;

    friend std::ostream& operator<<(std::ostream& os, const PersonEstates& person);

    void printAll();
};
#endif