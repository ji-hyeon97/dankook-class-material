#include<iostream>
#include <list> 
#include<string>
#include<vector>
using namespace std;

class Handler {
public:
	virtual Handler* SetNext(Handler* handler) = 0;
	virtual string Handle(string request) = 0;
};

class AbstractHandler : public Handler {
private:
	Handler* next_handler_;
public:
	AbstractHandler() : next_handler_(nullptr) { }
	Handler* SetNext(Handler* handler) {
		this->next_handler_ = handler;
		return handler;
	}
	string Handle(string request) {
		if (this->next_handler_) { return this->next_handler_->Handle(request); }
		return {};
	}
};

class AHandler : public AbstractHandler {
public:
	string Handle(string request) override {
		if (request == "A") { return "Request A Done"; }
		else { return AbstractHandler::Handle(request); }
	}
};

class BHandler : public AbstractHandler {
public:
	string Handle(string request) override {
		if (request == "B") { return "Request B Done"; }
		else { return AbstractHandler::Handle(request); }
	}
};

int main() {
	AHandler* a = new AHandler;
	BHandler* b = new BHandler;
	a->SetNext(b);
	vector<string> requests = { "B", "C", "A" };
	for (const string& f : requests) {
		const string result = a->Handle(f);
		if (!result.empty()) {
			cout << result << endl;
		}
		else {
			cout << "Request " << f << " left untouched." << endl;
		}
	}
	return 0;
}