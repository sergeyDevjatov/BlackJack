#pragma once
#include <vector>

using std::vector;

class Observer;

class Observable
{
	public:
	virtual ~Observable();
	virtual void Notify() final;

	virtual void Add(Observer* observer);

	private:

	vector <Observer*> observers;
};

class Observer
{
	public:
	virtual ~Observer();
	virtual void Update(const Observable* notifier);
	virtual void Attach(Observable* attachableObservable);


	protected:

	virtual void Update() = 0;
	Observable* observable;
};