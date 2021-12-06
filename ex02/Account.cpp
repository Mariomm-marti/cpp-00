#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts;
	displayStatus();
	_nbAccounts++;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	previousAmount;

	previousAmount = _amount;
	_totalNbDeposits++;
	_nbDeposits++;
	_totalAmount += deposit;
	_amount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << previousAmount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	if (withdrawal > _amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	_amount -= withdrawal;
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount(void) const
{
	return _amount;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t	time;
	std::tm		*now;

	time = std::time(0);
	now = std::localtime(&time);
	std::cout << "[";
	std::cout << (now->tm_year + 1900);
	std::cout << std::setfill('0') << std::setw(2) << (now->tm_mon + 1);
	std::cout << std::setfill('0') << std::setw(2) << (now->tm_mday + 1);
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2) << (now->tm_hour + 1);
	std::cout << std::setfill('0') << std::setw(2) << (now->tm_min + 1);
	std::cout << std::setfill('0') << std::setw(2) << (now->tm_sec + 1);
	std::cout << "] ";
}

