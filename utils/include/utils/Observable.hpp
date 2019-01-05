// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ SUBJECT.HPP ___________ 
//================================

#pragma once

#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include "Observer.hpp"
#include <iostream>

namespace utils {

    template<typename U>
	class Observable {
		public:
            Observable()
            : _observers(), _observerID(0), _ptr(new Observable*(this))
            {
                _observers.reserve(10);
            }

            ~Observable() {
                if(_ptr != nullptr) {
                    *_ptr = nullptr;
                }

                for(auto jt = _observers.begin(); jt != _observers.end(); ++jt) {
                    delete *jt;
                }

            }

            inline const unsigned int attach(const std::function<void(U&)> &action) {
                _observers.emplace(new Observer<U>(action, _observerID));
                return _observerID++;
            }

            inline void detach(const unsigned int &id) {
                auto it = findObserver(id);
                delete *it;
                _observers.erase(it);
            }

            inline void notifyAll(U &target) {
                for(auto it = _observers.begin(); it != _observers.end(); it++) {
                    (*it)->update(target);
                }
            }

            inline void notify(const unsigned int &id, U &target) {
                (*findObserver(id))->update(target);
            }

            inline void notify(const std::set<unsigned int> &id, U &target) {
                unsigned int found = 0;
                for(auto jt = _observers.begin(); jt != _observers.end() && found < _observers.size(); ++jt) {
                    if(*jt != nullptr && id.find((*jt)->id()) != id.end()) {
                        (*jt)->update(target);
                        ++found;
                    }
                }
            }

            inline Observable ** ptr() const {
                return _ptr;
            }

            inline void clearObservers() {
                _observers.clear();
                _observerID = 0;
            }

        private:
            std::unordered_set<Observer<U>*> _observers;
            unsigned int _observerID;
            Observable ** _ptr;
            inline const typename std::unordered_set<Observer<U>*>::iterator findObserver(const unsigned int &id) {
                for(auto jt = _observers.begin(); jt != _observers.end(); ++jt) {
                    if((*jt)->id() == id)
                        return jt;
                }
            }

	};

    template<>
	class Observable<void> {
		public:
            Observable()
            : _observers(), _observerID(0), _ptr(new Observable<void>*(this))
            {
                _observers.reserve(10);
            }

            ~Observable() {
                if(_ptr != nullptr) {
                    *_ptr = nullptr;
                }

                for(auto jt = _observers.begin(); jt != _observers.end(); ++jt) {
                    delete *jt;
                }

            }

            inline const unsigned int attach(const std::function<void(void)> &action) {
                _observers.emplace(new Observer<void>(action, _observerID));
                return _observerID++;
            }

            inline void detach(const unsigned int &id) {
                auto it = findObserver(id);
                delete *it;
                _observers.erase(it);
            }

            inline void notifyAll() {
                for(auto it = _observers.begin(); it != _observers.end(); it++) {
                    (*it)->update();
                }
            }

            inline void notify(const unsigned int &id) {
                (*findObserver(id))->update();
            }

            inline void notify(const std::set<unsigned int> &id) {
                unsigned int found = 0;
                for(auto jt = _observers.begin(); jt != _observers.end() && found < _observers.size(); ++jt) {
                    if(id.find((*jt)->id()) != id.end() && *jt != nullptr) {
                        (*jt)->update();
                        ++found;
                    }
                }
            }

            inline Observable ** ptr() const {
                return _ptr;
            }

            inline void clearObservers() {
                _observers.clear();
                _observerID = 0;
            }

        private:
            std::unordered_set<Observer<void>*> _observers;
            unsigned int _observerID;
            Observable<void> ** _ptr;
            inline const std::unordered_set<Observer<void>*>::iterator findObserver(const unsigned int &id) {
                for(auto jt = _observers.begin(); jt != _observers.end(); ++jt) {
                    if((*jt)->id() == id)
                        return jt;
                }
            }

	};
    
}