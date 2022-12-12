#include "fiberline.h"

#include <math.h>

FiberLine::FiberLine(double exitLvl, double recievedLvl, int connectionsCount,
                     double avgConnectionLoss, double extraLoss,
                     double systemBuffer, double kmAttenuation,
                     double avgSpliceLoss, double constructionLength, double spectralWidth) {
  this->exitLvl = exitLvl;
  this->recievedLvl = recievedLvl;
  this->connectionsCount = connectionsCount;
  this->avgConnectionLoss = avgConnectionLoss;
  this->extraLoss = extraLoss;
  this->systemBuffer = systemBuffer;
  this->kmAttenuation = kmAttenuation;
  this->avgSpliceLoss = avgSpliceLoss;
  this->constructionLength = constructionLength;
  this->spectralWidth = spectralWidth;
}

double FiberLine::spliceLoss() { return avgSpliceLoss / constructionLength; }

double FiberLine::connectionLoss() {
  return connectionsCount * avgConnectionLoss;
}

double FiberLine::lengthByAttenuation() {
  return (exitLvl - recievedLvl - connectionLoss() - extraLoss - systemBuffer) /
         (kmAttenuation + spliceLoss());
}

double FiberLine::lengthByDispersion() {
  double lightSpeed = 299792.458; // km/sec
  double impulseWidth = 0.096;
  double waveLength = 1.55;
  double chromaDispersion = -6.5; // -(5-8)

  return abs((2 * M_PI * lightSpeed * pow(impulseWidth, 2)) /
          (pow(waveLength, 2) * chromaDispersion *
           sqrt(1 + 4 * pow(M_PI, 2) * pow(spectralWidth, 2) *
                        pow(impulseWidth, 2))));
}
