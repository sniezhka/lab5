template <typename T1, typename T2, typename T3>
class PersonalData{
public:
	string ClassName(T3 ob){// ������� ��'� �����
		return typeid(ob).name();
	}
	PersonalData(){}
	T1 profit;//�������
	T1 costs;// �������
	T2 company_account;
	T2 costs_account;
	string status;
	void setStatus(T3 ob){
		status = ClassName(ob);
	}

	T1 NetProfit(){
		T1 net_profin = profit - costs;
		return net_profin;
	}
	void SaveMoneyOn(){
		money_on_the_bank += NetProfit();
	}
	T1 CompanyMoney(){
		return profit / 5;
	}
	void SeeOwnersMoney(){
		cout << "Money on: " << company_account << CompanyMoney() << endl;
	}
	T1 getBankMoney(){
		return money_on_the_bank;
	}
	void setBankMoney(T1 money_on_the_bank){
		this->money_on_the_bank = money_on_the_bank;
	}
	T1 money_on_the_bank;
};