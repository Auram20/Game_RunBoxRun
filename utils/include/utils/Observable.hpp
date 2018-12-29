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

    template<typename T, typename U>
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
                    std::set<Observer<U>*> second = it->second;
                    for(auto jt = second.begin(); jt != second.end(); ++jt) {
                        delete *jt;
                    }
                    second.clear();
                }
            }


            inline void attach(const T &eventName, Observer<U> *o) {
                if(_observers.find(eventName) == _observers.end()) {
                   _observers.emplace(eventName, std::set<Observer<U>*>({o}));
                } else {
                    findEventObservers(eventName)->emplace(o);
                }
            }

            inline void detach(const T &eventName) {
                _observers.erase(eventName);
            }

            inline void notifyAll(const U &target) {
                for(auto it = _observers.begin(); it != _observers.end(); ++it) {
                    notify(it->first, target);
                }
            }

            inline void notify(const T &eventName, const U &target) {
                std::set<Observer<U>*> *setObservers = findEventObservers(eventName);
                for(auto it = setObservers->begin(); it != setObservers->end(); it++) {
                    (*it)->update(target);
                }
            }

            inline std::set<Observer<U>*> *findEventObservers(const T &eventName) {
                if(_observers.find(eventName) == _observers.end()) return nullptr; //Error !
                return &(_observers.at(eventName));
            }

            inline Observable ** ptr() const {
                return _ptr;
            }

        private:
            std::map<T, std::set<Observer<U>*>> _observers;
            Observable ** _ptr;

	};
    
}