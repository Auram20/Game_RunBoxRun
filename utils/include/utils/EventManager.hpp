// ================================
// OPENGL / C++ - IMAC 2
// _________ RUNBOXRUN ___________ 
// _________ INPUTMANAGER.HPP_____ 
//================================

#ifndef __EVENTMANAGER__HPP
#define __EVENTMANAGER__HPP

#include <map>
#include <set>
#include <iostream>
#include <utils/Observer.hpp>
#include <utils/Observable.hpp>

namespace utils
{


	/// \class EventManager
	/// \brief class defining the event manager.
    template<typename U>
	class EventManager
	{
			
		public:
		
        EventManager()
        : _observables()
        {
            //_observables.reserve(100);
            //_observables.fill(nullptr);
        }

        ~EventManager() = default;

		inline int attach(Observable<U> &target, const std::function<void(U&)> &action) {
            if(target.ptr() == nullptr || *(target.ptr()) == nullptr) return -1;
			_observables.emplace(target.ptr());
			return target.attach(action);
		}

		inline void update(Observable<U>** observable, const std::set<unsigned int> &id, U &target) {
			auto it = _observables.find(observable);
			if(it == _observables.end()) return;
			if(**it != nullptr) {
				(**it)->notify(id, target);
			} else {
				_observables.erase(it);
			}
		}

		inline void updateAll(U &target) {
			for(auto it = _observables.begin(); it != _observables.end(); ++it) {
                if(**it != nullptr)
				    (**it)->notifyAll(target);
                else
                    delete *it;
			}
		}

		private:
			std::set<Observable<U>**> _observables;
	};

	/// \class EventManager
	/// \brief class defining the event manager.
    template<>
	class EventManager<void>
	{
			
		public:
		
        EventManager()
        : _observables()
        {
            //_observables.reserve(100);
            //_observables.fill(nullptr);
        }

        ~EventManager() = default;

		inline int attach(Observable<void> &target, const std::function<void(void)> &action) {
            if(target.ptr() == nullptr || *(target.ptr()) == nullptr) return -1;
			_observables.emplace(target.ptr());
			return target.attach(action);
		}

		inline void update(Observable<void>** observable, const std::set<unsigned int> &id) {
			auto it = _observables.find(observable);
			if(it == _observables.end()) return;
			if(**it != nullptr) {
				(**it)->notify(id);
			} else {
				_observables.erase(it);
			}
		}

		inline void updateAll() {
			for(auto it = _observables.begin(); it != _observables.end(); ++it) {
                if(**it != nullptr)
				    (**it)->notifyAll();
                else
                    delete *it;
			}
		}

		private:
			std::set<Observable<void>**> _observables;
	};
}

#endif