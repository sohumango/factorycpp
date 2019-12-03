#include "clsEnsObj.hpp"

BaseFactory::map_type   * BaseFactory::m_map;
BaseFactory::map_etype  * BaseFactory::m_emap;

clsEnsObj::clsEnsObj()
{
    m_etype = clsEnsObj::e_none;
}

clsEnsObj::~clsEnsObj()
{
    
}

std::string clsEnsObj::GetName()
{
    return "base";
}

//==============================================================================
clsEnsObj * BaseFactory::createInstance(std::string const& s)
{
    map_type::iterator it = m_map->find(s);
    if(it == m_map->end())
    {
        return NULL;
    }
    clsEnsObj * ptrobj = it->second();
    return ptrobj;
}

clsEnsObj * BaseFactory::createInstance(clsEnsObj::etype const e)
{
    map_etype::iterator it = m_emap->find(e);
    if(it == m_emap->end())
    {
        return NULL;
    }
    clsEnsObj * ptrobj = it->second();
    return ptrobj;
}

BaseFactory::map_type * BaseFactory::getMap()
{
    if(!m_map)
    {
        m_map =  new map_type;
    }
    return  m_map;
}

BaseFactory::map_etype * BaseFactory::getEMap()
{
    if(!m_emap)
    {
        m_emap =  new map_etype;
    }
    return  m_emap;
}