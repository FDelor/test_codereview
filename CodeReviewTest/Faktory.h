#ifndef FAKTORIY_H
#define FAKTORIY_H

#include <QSharedPointer>
#include <QWeakPointer>
#include <QHash>
#include <QMutex>

template<typename Type,typename KeyType>
class Faktory
{
public:

    Faktory(){}

    virtual ~Faktory(){
        m_instances.clear();
    }

    QSharedPointer<Type> getInstance(KeyType key){
        QSharedPointer<Type> inst ;
        QMutexLocker lock(m_mutex);
        Q_UNUSED(lock);
        if(m_instances.contains(key)){
            inst = m_instances.value(key).toStrongRef();
        }
        if(inst.isNull()){
            inst.reset(new Type());
            m_instances.insert(inst, inst.toWeakRef());
        }
        return inst;
    }

    QHash<KeyType, QWeakPointer<Type>> m_instances;
    QMutex m_mutex;
};

#endif // FAKTORIY_H
