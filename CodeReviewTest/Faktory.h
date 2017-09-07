#ifndef FAKTORIY_H
#define FAKTORIY_H

#include <QSharedPointer>
#include <QWeakPointer>
#include <QHash>

template<typename Type,typename KeyType>
class Faktory
{
public:

    Faktory(){}
    ~Factory(){
        m_instances.clear();
    }

    QSharedPointer<Type> getInstance(KeyType key){
        QSharedPointer<Type> inst ;
        if(m_instances.contains(key)){
            inst = m_instances.value(key).toStrongRef();
        }
        if(inst.isNull()){
            inst.reset(new Type());
            m_instances.insert(type, inst.toWeakRef());
        }
        return inst;

    }




    QHash<KeyType, QWeakPointer<Type>> m_instances;
};

#endif // FAKTORIY_H
