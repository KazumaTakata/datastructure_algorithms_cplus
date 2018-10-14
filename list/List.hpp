
#ifndef LIST_H
#define LIST_H

#include <stdexcept>

class List
{
  private:
    double *list;
    int length;

  public:
    List()
    {
        length = 0;
        list = new double;
    }

    double get(int i)
    {
        if (-1 < i && i < length)
        {
            return list[i];
        }
        else
        {
            throw std::invalid_argument("index of list is out of range.");
        }
    }

    void insert(int i, double v)
    {
        double *newlist;
        if (-1 < i && i < length)
        {
            for (int j = 0, j2 = 0; j < length + 1; j++)
            {
                if (j == i)
                {
                    newlist[i] = v;
                    j++;
                    length += 1;
                }
                else
                {
                    newlist[j] = list[j2];
                }

                j2++;
            }
            list = newlist;
        }
        else
        {
            throw std::invalid_argument("index of list is out of range.");
        }
    }

    int search(double v)
    {
        for (int i = 0; i < length; i++)
        {
            if (list[i] == v)
            {
                return i;
            }
        }

        return -1;
    }

    void remove(int i)
    {
        double *newlist = new double[length - 1];
        bool alreadyremoved = false;
        if (-1 < i && i < length)
        {
            for (int j = 0, j2 = 0; j < length; j++)
            {
                if (j == i && !alreadyremoved)
                {
                    j--;
                    length -= 1;
                    alreadyremoved = true;
                }
                else
                {
                    newlist[j] = list[j2];
                }

                j2++;
            }
            double *oldlist = list;

            list = newlist;

            delete[] oldlist;
            oldlist = NULL;
        }
        else
        {
            throw std::invalid_argument("index of list is out of range.");
        }
    }

    void append(double value)
    {
        list[length] = value;
        length += 1;
    }
};

#endif