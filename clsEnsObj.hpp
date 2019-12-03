#ifndef ENSOBJ_HPP
#define ENSOBJ_HPP

#include <iostream>
#include <map>
#include <memory>

/// macro to get class name string
#define CLASS_NAME(NAME) #NAME

/// declare ensregister<clsTelNc> etc.. type
#define REGISTER_DEC_TYPE(NAME) static EnsRegister<NAME> reg
/// init ensregister type to add class and creator to map.
//#define REGISTER_DEF_TYPE(NAME)  EnsRegister<NAME> NAME::reg(#NAME)
#define REGISTER_DEF_TYPE(NAME, abc) EnsRegister<NAME> NAME::reg(#NAME, abc)

/// base ens object class
class clsEnsObj {
   public:
    /// object type.
    enum etype {
        /// none for init or error.
        e_none = 0,
        /// SeqRegister
        e_reg = 1,
        /// SeqMatcher
        e_auth = 2,
        /// SrgUserData
        e_strage = 3
    };

   public:
    clsEnsObj();

    virtual ~clsEnsObj();

    /// get object type.
    /**
     *  @return      ens object class type
     */
    virtual etype GetEType() { return m_etype; };

    /// get class readable name
    virtual std::string GetName();

   protected:
    /// object type. tel com time or server.
    etype m_etype;
};

/// shared pointer for ens object.
typedef std::shared_ptr<clsEnsObj> clsEnsObjPtr;

//==============================================================================
/// class factory using for create instance dynamic.
struct BaseFactory {
    /// define ens object class creator map for registing.
    typedef std::map<std::string, clsEnsObj *(*)()> map_type;
    typedef std::map<clsEnsObj::etype, clsEnsObj *(*)()> map_etype;

   public:
    /// get ens object class map pointer.
    static map_type *getMap();

    /// get ens object class map pointer.
    static map_etype *getEMap();

    /// create instance for class name s.
    /**
     *  @param[in] s         class name string
     *  @return              class object instance.
     */
    static clsEnsObj *createInstance(std::string const &s);

    static clsEnsObj *createInstance(clsEnsObj::etype const e);

   private:
    /// ens object class map. classname<->object creator.
    static map_type *m_map;
    static map_etype *m_emap;
};

//==============================================================================
/// create instance from  typename.
template <typename T>
clsEnsObj *createT() {
    return new T;
}

/// ens object register class.
template <typename T>
struct EnsRegister : BaseFactory {
    /// init ens register class to add class name and creator to map.
    /**
     *  @param[in] s         class name string
     */
    EnsRegister(std::string const &s, int abc) : BaseFactory() {
        getMap()->insert(std::make_pair(s, &createT<T>));
        clsEnsObj *ptrobj = createT<T>();
        clsEnsObj::etype typ = ptrobj->GetEType();
        getEMap()->insert(std::make_pair(typ, &createT<T>));
        std::cout << "____reg:" << s << " <-> " << std::endl;
        delete ptrobj;
    }
};

#endif