#include "Observer.h"

Observer::~Observer() { }

void Observer::Update(const Observable* notifier)
{
	if (notifier == observable)
		Update();
}


void Observer::Attach(Observable* attachableObservable)
{
	observable = attachableObservable;
}

Observable::~Observable() { }

void Observable::Notify()
{
	for (auto observer = observers.begin(); observer != observers.end(); ++observer)
		(*observer)->Update(this);
}

void Observable::Add(Observer* observer)
{
	observers.push_back(observer);
}
