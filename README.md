# Fuzzy Systems Project

MATLAB and Simulink code for the Fuzzy Systems course project at Aristotle University of Thessaloniki (2024–25).

| Folder | Topic |
|---|---|
| `ex1` | Fuzzy logic controller for DC motor speed control (Simulink), tested in three scenarios with initial and fine-tuned gains |
| `ex2` | Fuzzy logic controller that steers a car around obstacles to a target point, with initial and fine-tuned FIS |
| `ex3` | TSK fuzzy models for regression (Airfoil Self-Noise and Superconductivity datasets): ANFIS training, grid partitioning and subtractive clustering, ReliefF feature selection, 5-fold cross-validation |
| `ex4` | TSK fuzzy models for classification (Haberman's Survival and Epileptic Seizure Recognition datasets), evaluated with accuracy and Cohen's kappa |

## Requirements

MATLAB with the Fuzzy Logic Toolbox, Statistics and Machine Learning Toolbox, and Simulink.

## Run

Open MATLAB, set an exercise folder as the current folder and run its script:

| Folder | Script |
|---|---|
| `ex1` | `DC_Motor_FLC`, `DC_Motor_FLC_senario2`, `DC_Motor_FLC_senario3` |
| `ex2` | `ex2` |
| `ex3` | `regression_TSK_1`, `regression_TSK_2` |
| `ex4` | `TSK_classification_1`, `TSK_classification_1_P2`, `TSK_classification_2` |

The datasets are in the same folders as the scripts. Simulink build files (`slprj/`, `*.slxc`) are regenerated on first run.
