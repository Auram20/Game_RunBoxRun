// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ SUBJECT.HPP ___________ 
//================================

#pragma once

#include <map>
#include <set>
#include <algorithm>
#include "Observer.hpp"

namespace utils {

    template<typename T>
	class Observable {
		public:
            Observable()
            : _observers(), _ptr(new Observable*(this))
            {

            }

            ~Observable() {
                if(_ptr != nullptr) {
                    *_ptr = nullptr;
                }
                for(auto it = _observers.begin(); it != _observers.end(); ++it) {
                    std::set<AbstractObserver*> second = it->second;
                    for(auto jt = second.begin(); jt != second.end(); ++jt) {
                        delete *jt;
                    }
                    second.clear();
                }
            }


            inline void attach(const T &eventName, AbstractObserver *o) {
                if(_observers.find(eventName) == _observers.end()) {
                   _observers.emplace(eventName, std::set<AbstractObserver*>({o}));
                } else {
                    findEventObservers(eventName)->emplace(o);
                }
            }

            inline void detach(const T &eventName) {
                _observers.erase(eventName);
            }

            inline void notifyAll() {
                for(auto it = _observers.begin(); it != _observers.end(); ++it) {
                    notify(it->first);
                }
            }

            inline void notify(const T &eventName) {
                std::set<AbstractObserver*> *setObservers = findEventObservers(eventName);
                for(auto it = setObservers->begin(); it != setObservers->end(); it++) {
                    (*it)->update(this);
                }
            }

            inline std::set<AbstractObserver*> *findEventObservers(const T &eventName) {
                if(_observers.find(eventName) == _observers.end()) return nullptr; //Error !
                return &(_observers.at(eventName));
            }

            inline Observable ** ptr() const {
                return _ptr;
            }

        private:
            std::map<T, std::set<AbstractObserver*>> _observers;
            Observable ** _ptr;

	};
    
}