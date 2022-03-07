#include "pressure.hpp"
double pressure::pressure_drop(double den, double v)
{
    double p;
    p = (den * v * v) / (2 * 9.81);
    return p;
}
double pressure::tip(double temp, double wt, double den, double f)
{

    double  t,od, id, fa, p1,v; 
    std::cout << "enter thickness" << std::endl;
    std::cin >> t;
    std::cout << "enter outer diameter in mm" << std::endl;
    std::cin >> od;

    id = od - (2 * t);           //calculating inner diameter
    fa = (3.1415 / 4) * id * id;   // calculating flow area
    v = (f / fa);                 //calculating velocity
    p1 = pressure_drop(den, v);    // calculating pressure drop in flare tip
    return p1;
}

double pressure::riser(double temp, double wt, double den, double f)
{
    
    double t, od, id, fa, p2, ff,l,v;
    std::cout << "enter thickness ";
    std::cin >> t;

    std::cout << "enter riser length ";

    std::cin >> l;
    std::cout << "enter outer thickness ";
    std::cin >> od;

    id = od - (2 * t);             //calculating riser inner diameter
    fa = (3.14 / 4) * id * id;       //calculating  flow area in riser
    v = f / fa;                 //calculating velocity
    ff = 0.079 / (pow(den, 0.025));  //calculating friction factor
    p2 = (ff / 144) * (l / id) * ((den * v * v) / (2 * 32.185) * 703.3);  //calculating pressure drop in riser
    return p2;
}
double pressure::molecularseal(double temp, double wt, double den, double f)
{
    double  df, t, od, id, fa, p3,v;
    std::cout << "enter thickness";
    std::cin >> t;
    std::cout << "enter outer diameter";
    std::cin >> od;
    id = (od * 2.54) - (2 * t);  //calculating seal inner diameter
    fa = (3.14 / 4) * id * id;   //calculating flow area
    v = f / fa;             //calculating velocity
    df = 3.5 * (0.035 * (od - t));   // calculating discharge coefficient
    p3 = pressure_drop(den, v) * df;   //calculating presuure drop in molecular seal
    return p3;
}
double pressure::waterseal(double temp, double wt, double den, double f)
{
    double p_at_entry,l, t1,t2, inletod, inletid, outletod, fa, p4, outletid, fa1, v1,v;
    std::cout << "enter water seal inlet outer diameter ";
    std::cin >> inletod;
    std::cout << "enter thickness of inlet ";
    std::cin >> t1;
    std::cout << "enter water seal outlet outer diameter ";
    std::cin >> outletod;
    std::cout << "enter thickness of outlet ";
    std::cin >> t2;
    std::cout << "enter dipped length ";
    std::cin >> l;
    inletid = inletod - (2 * t1);    // calculating water seal inlet inner diameter
    fa = (3.14 / 4) * inletid * inletid; // calculating flow area(inlet)
    v = f / fa;          // calculating flow velocity (inlet)
    outletid = outletod - (2 * t2);   // calculating water seal outlet inner diameter
    fa1 = (3.14 / 4) * outletid * outletid; // calculating flow area(outlet)
    v1 = f / fa;
    p_at_entry = pressure_drop(den, v) + (0.25 * v * v);  //calculating pressure drop at entry
    p4 = p_at_entry + l;                   // calculating pressure drop in water seal
    return p4;
}
double pressure::kod(double temp, double wt, double den, double f)
{
    double v, t, od, iid, oid, fa, p5;
    std::cout << "enter kod seal inlet outer diameter ";
    std::cin >> od;
    std::cout << "enter thickness ";
    std::cin >> t;
    iid = (od * 25.4) - (2 * t); // calculating inner inlet diameter
    fa = (3.14 / 4) * iid * iid;  //calculating flow area
    oid = (od * 25.4) - (2 * t);// calculating outer inlet diameter
    v = f / fa;              // calculating velocity
    p5 = pressure_drop(den, v) + (0.5 * v * v); //calculating pressuredrop in KOD
    return p5;
}
double pressure::velocityseal(double temp, double wt, double den, double f)
{
    double od, t, id, v, p, p6, pf = 1.0;
    std::cout << "enter seal outer diameter ";
    std::cin >> od;
    std::cout << "enter seal thickness ";
    std::cin >> t;
    std::cout << "enter velocity ";
    std::cin >> v;
    std::cout << "enter thickness ";
    std::cin >> t;

    id = ((od * 25.4) - (2 * t)) / 1000;    // calculating inner diameter
    p = 17500 * pow((v / (1000 * od * od)), 2);// calculating pressure drop in velocityseal(DPCS)
    p6 = p / pf;
    return p6;
}
double pressure::total_pressure_drop(double temp,double wt,double den, double f)
{
    double tp;
    tp = tip(temp, wt, den, f) + riser(temp, wt, den, f) + molecularseal(temp, wt, den, f) + waterseal(temp, wt, den, f) + kod(temp, wt, den, f) + velocityseal(temp, wt, den, f);
    return tp;
}


