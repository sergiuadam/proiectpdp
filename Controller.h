#pragma once
#include <vector>
#include "Materie.h"
#include <boost/asio.hpp>
#include <boost/thread.hpp>
using namespace std;

class Controller
{
	vector<Materie *> materii;
	boost::asio::thread_pool * p;
public:
	Controller(vector<Materie *> lista) {
		this->materii = lista;
		p = new boost::asio::thread_pool(4);
	}
	// Lista cu materii 
	// O materie are:	-lista cu profesorii de la materie
	//					-lista cu clasele la care trebe predata
	//Ce trebuie facut:
	// -Pentru fiecare materie, ii dam bataie

	void saiDamBataieBaieti() {
        auto t1 = boost::get_system_time();
        for (auto& materie : materii) {
            materie->rezolvaMateria();
        }
        auto t2 = boost::get_system_time();
        cout << "Secvential: " << (t2 - t1).total_microseconds() << " microseconds / " << (t2 - t1).total_milliseconds() << " milliseconds" << endl;
	}

	void saiDamBataieBaietiAsync() {
        auto t1 = boost::get_system_time();
        for (auto& materie : materii) {
            boost::asio::post(*p, [&](){
                materie->rezolvaMateria();
            });
        }
        p->join();
        auto t2 = boost::get_system_time();
        cout << "Paralel: " << (t2 - t1).total_microseconds() << " microseconds / " << (t2 - t1).total_milliseconds() << " milliseconds" << endl;
	}
};

