#ifndef FIBERLINE_H
#define FIBERLINE_H

class FiberLine {
public:
  FiberLine(double exitLvl, double recievedLvl, int connectionsCount,
            double avgConnectionLoss, double extraLoss, double systemBuffer,
            double kmAttenuation, double avgSpliceLoss,
            double constructionLength, double spectralWidth);

  double spliceLoss();
  double connectionLoss();
  double lengthByAttenuation();
  double lengthByDispersion();

private:
  double exitLvl;
  double recievedLvl;
  int connectionsCount;
  double avgConnectionLoss;
  double extraLoss;
  double systemBuffer;
  double kmAttenuation;
  double avgSpliceLoss;
  double constructionLength;
  double spectralWidth;
};

#endif // FIBERLINE_H
