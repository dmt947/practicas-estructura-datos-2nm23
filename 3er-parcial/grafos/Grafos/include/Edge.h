#ifndef EDGE_H
#define EDGE_H


class Edge
{
public:
    Edge(const char* n, double t, double c);
    ~Edge();

    const char* getName() const;
    double getTime() const;
    double getCost() const;

    void setName(const char* n);
    void setTime(double t);
    void setCost(double c);
protected:

private:
    char* name;
    double time, cost;
};

#endif // EDGE_H
