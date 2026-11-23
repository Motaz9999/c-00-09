#include <iostream>
#include <stdexcept>

// basic guarantee example : if the second update throws
// the first has already taken effect. the obj remain valid and perfectly
// safe to keep using -- no leaks , no crash , no broken invariant -- but
// its content is not what the caller asked for and cannot be rolled back
// to what it was before the call.
class Wallet
{
private:
    int _usd;
    int _eur;

public:
    Wallet(int usd, int eur) : _usd(usd), _eur(eur)
    {
    }
    int getUSD() const
    {
        return _usd;
    }
    int getEUR() const
    {
        return _eur;
    }
    void basicGuaranteeUpdate(int newUSD, int newEUR)
    {
        _usd = newUSD; // take effect immediately

        if (newEUR < 0)
            throw std::invalid_argument("EUR balance cannot be negative");
        _eur = newEUR; // never reach this so now half the obj is different
    }
};

// STRONG GUARANTEE example, built via the copy-and-swap idiom:
// the entire "would-be" new state is validated and built OFF TO THE SIDE
// first. *this is only ever touched by swap(), which cannot fail. So
// either the whole update happens, or none of it does -- there is no
// partially-updated state possible.

class TransactionalWallet
{
private:
    int _usd;
    int _eur;

public:
    TransactionalWallet(int usd, int eur) : _usd(usd), _eur(eur) {}
    int getUSD() const { return _usd; }
    int getEUR() const { return _eur; }
    // NO-THROW GUARANTEE: built entirely out of primitive
    // assignments on built-in int members. There is nothing in
    // this function that can fail, so it can never leave either
    // wallet half-swapped.
    void swap(TransactionalWallet &other) throw()
    {
        int tempUSD = _usd;
        _usd = other._usd;
        other._usd = tempUSD;

        int tempEUR = _eur;
        _eur = other._eur;
        other._eur = tempEUR;
    }

    void strongGuaranteeUpdate(int newUSD, int newEUR)
    {
        if (newEUR < 0)
            throw std::invalid_argument("EUR balance cannot be negative");
        // see now there is no value changes so this is not basic guarantee
        // now the next step is using temp obj that have new values then copy these values
        // into the old obj with no throw fun
        TransactionalWallet tmp(newUSD, newEUR); // no throw happen
        swap(tmp);                               // commit -- guaranteed not to throw
    }
};

int main()
{
    std::cout << "--- BASIC GUARANTEE: partial modification on failure ---" << std::endl;
    Wallet w(100, 50);

    std::cout << "Before: USD=" << w.getUSD() << " EUR=" << w.getEUR() << std::endl;

    try
    {
        w.basicGuaranteeUpdate(500, -10);
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }
    std::cout << "After:  USD=" << w.getUSD() << " EUR=" << w.getEUR() << std::endl;
    std::cout << "USD changed to 500 even though the whole call 'failed'." << std::endl; // base gran...

    std::cout << "The wallet is still perfectly valid and usable -- just not" << std::endl;

    std::cout << "in the state the caller intended. That's the basic guarantee." << std::endl;

    std::cout << "\n--- STRONG GUARANTEE: all-or-nothing via copy-and-swap ---" << std::endl;

    TransactionalWallet tw(100, 50);
    std::cout << "Before: USD=" << tw.getUSD() << " EUR=" << tw.getEUR() << std::endl;

    try
    {
        tw.strongGuaranteeUpdate(500, -10);
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }
    std::cout << "After:  USD=" << tw.getUSD() << " EUR=" << tw.getEUR() << std::endl;
    std::cout << "Nothing changed at all -- not even USD. The failed validation" << std::endl;
    std::cout << "happened before *this was ever touched." << std::endl;

 std::cout << "\n--- NO-THROW GUARANTEE: swap() itself cannot fail ---" << std::endl;
    TransactionalWallet a(1, 2);
    TransactionalWallet b(9, 8);

    std::cout << "a: USD=" << a.getUSD() << " EUR=" << a.getEUR() << std::endl;
    std::cout << "b: USD=" << b.getUSD() << " EUR=" << b.getEUR() << std::endl;
        a.swap(b);
    std::cout << "swap() only moves primitive ints around -- there is no operation" << std::endl;
    std::cout << "inside it capable of throwing, at all." << std::endl;
    std::cout << "a: USD=" << a.getUSD() << " EUR=" << a.getEUR() << std::endl;
    std::cout << "b: USD=" << b.getUSD() << " EUR=" << b.getEUR() << std::endl;
    std::cout << "\n--- End of program ---" << std::endl;
    return 0;

}