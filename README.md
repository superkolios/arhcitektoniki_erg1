# Αρχιτεκτονική Υπολογιστών Εργαστήριο 1

Ομάδα 3

- Φίλιππος Τόλιας ΑΕΜ: 10252
- Χρήστος-Μάριος Περδίκης ΑΕΜ: 10075

#### 1. Ανοίξτε το αρχείο starter_se.py που χρησιμοποιήσατε στο παράδειγμα του Hello World και προσπαθήστε να καταλάβετε ποιες είναι βασικές παράμετροι που έχει περάσει στον gem5 για το σύστημα προς εξομοίωση. Καταγράψτε τα βασικά χαρακτηριστικά του συστήματος, όπως τύπος CPU, συχνότητα λειτουργίας, βασικές μονάδες, caches, μνήμη κτλ.

- **cpu-type**: minor (από το argument --cpu="minor")
- **Μερικα χαρακτηρηστικα απο τις caches**(από το αρχείο devices.py):
  - **L1i cache**:
    - **size**: 48 kB
    - **association**: 3
  - **L1d cache**:
    - **size**: 32 kB
    - **association**: 2
    - **write buffer**: 2
  - **L2 cache**:
    - **size**: 1MB
    - **association**: 16
    - **write buffer**: 8
- **cpu frequency**: 4Ghz
- **number of cores**: 1
- **memory type**: DDR3_1600_8x8
- **memory channels**: 2
- **memory ranks**: None
- **memory size**: 2 GiB


#### 2. Εκτός από το αρχείο εξόδου stats.txt που παράγεται στο τέλος της εξομοίωσης, ο gem5 παράγει και τα αρχεία config.ini και config.json. Τα αρχεία αυτά παρέχουν πληροφορίες για το σύστημα που εξομοιώνει ο gem5.

###### a. Χρησιμοποιήστε τα αρχεία αυτά για να επαληθεύσετε την απάντηση σας στο πρώτο ερώτημα. Παραθέστε τα σχετικά πεδία.

- **cpu-type**: system.cpu_cluster.cpus.type = BaseMinorCPU
- **l1i cache**:

  ```ini
  [system.cpu_cluster.cpus.icache.tags.indexing_policy]
  type=SetAssociative
  assoc=3
  entry_size=64
  eventq_index=0
  size=49152
  ```

- **l1d cache**:

  ```ini
  [system.cpu_cluster.cpus.dcache.tags.indexing_policy]
  type=SetAssociative
  assoc=2
  entry_size=64
  eventq_index=0
  size=32768
  ```

- **l2 cache**:

  ```ini
  [system.cpu_cluster.l2.tags.indexing_policy]
  type=SetAssociative
  assoc=16
  entry_size=64
  eventq_index=0
  size=1048576
  ```

- **cpu frequency**: `time_sync_period/system.cpu_cluster.clk_domain.clock (1000000000000/250)=4GHz`
- **number of cores**: `system.cpu_cluster.cpusnumThreads=1` (μάλλον)
- **memory type**: 
- **memory channels**: 
- **memory ranks**: None
- **memory size**: system.mem_ranges=0:2147483648 (2147483648 bytes = 2GB)

###### b. Τι είναι τα sim_seconds, sim_insts και host_inst_rate?

- **sim_seconds**: Number of seconds simulated.
- **sim_insts**: Number of instructions simulated.
- **host_inst_rate**: Simulator instruction rate (inst/s).

###### c. Ποιό είναι το συνολικό νούμερο των «committed» εντολών? Γιατί δεν είναι ίδιο το νούμερο με αυτό που παρουσιάζεται από στατιστικά που παρουσιάζονται από τον gem5?

Δεν είμαστε σίγουροι αν θέλει τα committed instructions ή committed operations

- Τα instructions committed είναι 5028 
- Τα operations committed είναι 5834
- simInsts 5028

###### d. Πόσες φορές προσπελάστηκε η L2 cache? Πώς θα μπορούσατε να υπολογίσετε τις προσπελάσεις αν δεν παρεχόταν από τον εξομοιωτή?

Βλέπουμε από το system.cpu_cluster.l2.overallAccesses::total ότι η L2 cache προσπελάστηκε συνολικά 479 φορές. Αν δεν μας έδιναν αυτό το νούμερο τα αποτελέσματα της προσομοίωσης, 
θα μπορούσαμε να προσθέσουμε τις συνολικές φορές που η L2 προσπελάστηκε για read και για write και να προσθέταμε τις δύο αυτές τιμές μαζί. Αν δεν έιχαμε ούτε αυτή την πληροφορία,
θα βρίσκαμε τις προσπελάσεις της L2 λαμβάνοντας υπόψιν πόσες εντολές read και write εκτέλεσε ο επεξεργαστής, και θα αφαιρούσαμε από αυτές τις φορές που προσπελάστηκαν για εγγραφή ή
ανάγνωση οι L1i, L1d και η κύρια μνήμη. Ο αριθμός που θα έμενε θα ήταν ο αριθμός προσπελάσεων της L2.

#### 3. Εκτός από τις πληροφορίες που παρέχονται σε αυτήν την άσκηση, είναι σημαντικό να μπορείτε να ανατρέχετε και να αναζητάτε πληροφορίες στη βιβλιογραφία. Έτσι χρησιμοποιώντας ως αρχή το site του gem5 (gem5.org) αναζητήστε πληροφορίες για τα διαφορετικά μοντέλα in-order CPUs που χρησιμοποιεί ο gem5 (hint: στο παράδειγμα χρησιμοποιήσατε το μοντέλο CPU: minor) και παραθέστε μια συνοπτική παράγραφο για καθένα από αυτά.

Τα μοντέλα CPU που υπάρχουν στον gem5 είναι **AtomicSimpleCPU**, **TimingSimpleCPU**, **O3CPU**, **MinorCPU** και **TraceCPU**.

- **SimpleCPU**:
Είναι ένα μοντέλο με in-order execution το οποίο συνήθως χρησιμοποιείται όταν δεν χρειάζεται ένα πιο ακριβές μοντέλο. Δεν μπορεί να χρησιμοποιηθεί από μόνο του αλλά χρησιμοποιεί ενα από τα ακόλουθα υπομοντέλα:  
  - **AtomicSimpleCPU**:  
  Χρησιμοποιεί atomic πρόσβαση στην μνήμη η οποία είναι λιγότερο ακριβής από την timing. Για να υπολογίσει το χρόνο πρόσβασης χρησιμοποιεί εκτιμησεις.  
  - **TimingSimpleCPU**:  
  Χρησιμοποιεί timing πρόσβαση στην μνήμη η οποία είναι πιο ακριβής. Μόλις γίνεται κάποιο request στη μνήμη η προσομοίωση της CPU σταματάει και περιμένει κάποιο response για να συνεχίσει.  


- **O3CPU**:  
To O3CPU (Out-Of-Order CPU) είναι ένα λεπτομερές ISA-independent μοντέλο επεξεργαστή το οποίο παρέχει ένα πολύ ακριβές μοντέλο χρονισμού. Αποτελείται από 5 pipeline stages 
(fetch, decode, rename, issue/execute/writeback, commit) και εκτελεί εντολές μόνο στο στάδιο execute, σε αντίθεση με άλλα μοντέλα που εκτελούν εντολές στην αρχή, ή στο τέλος του pipeline 
και χρησιμοποιούν ένα "timing backend" για χρονισμό. Αυτή η σχεδίαση του επιτρέπει να έχει πολύ ακριβή και αξιόπιστο χρονισμό και να μην χάνεται το out-of-order load interaction.  


- **TraceCPU**:  
Το μοντέλο TraceCPU έχει ως στόχο του την διερεύνηση του performance της μνήμης του συστήματος (caches, interconnects και main memory) με έναν πιο γρήγορο τρόπο από το μοντέλο O3CPU, αλλά 
διατηρώντας μια αποδεκτή ακρίβεια. Βασίζεται στην αναπαραγωγή timing and dependency annotated traces για μονοπύρηνα benchmarks τα οποία αντιστοιχίζονται σε 15 memory-sensitive SPEC2006 benchmarks και 
μερικές HPC proxy εφαρμογές. Τα traces αυτά (elastic traces) δημιουργούνται από το Elastic Trace Probe το οποίο είναι συνδεδεμένο με το μοντέλο O3CPU.  


- **MinorCPU**:  
Το MinorCPU είναι ένα in-order μοντέλο με fixed pipeline αλλά παραμετροποιήσιμες δομές δεδομένων και συμπεριφορά εκτέλεσης εντολών. Προορίζεται για μοντελοποίηση επεξεργαστών με strict
in-order execution behaviour και καθιστά δυνατή την οπτικοποίηση της θέσης μιας εντολής στο pipeline. Δεν υποστηρίζει παραλληλισμό και αποφεύγει χρήση δομών δεδομένων με μεγάλο αριθμό
life-cycle information.

#### b. Αν τα αποτελέσματα που παρατηρείτε διαφέρουν, με βάση όσα περιγράψατε για τα χαρακτηριστικά κάθε μοντέλου, δώστε μια εξήγηση των διαφορών που παρατηρείτε.  

- MinorCPU:  
   - simSeconds: 0.000209  
   - hostSeconds: 0.62

- TimingSimpleCPU  
   - simSeconds: 0.000361  
   - hostSeconds: 0.19

Παρατηρούμε πως τα simSeconds της προσομοίωσης με MinorCPU έχουν χαμηλότερη τιμή από τα simSeconds της προσομοίωσης με TimingSimpleCPU, αλλά τα hostSeconds της πρώτης είναι πιο πολλά από
τη δεύτερη. Αυτό συμβαίνει γιατί το μοντέλο MinorCPU είναι πιο ακριβό σε performance και πιο περίπλοκο από το TimingSimpleCPU αλλά πιο αποδοτικό όταν τρέχουμε το πρόγραμμά μας. Για αυτό
στην προσομοίωση με MinorCPU, το πρόγραμμά μας έτρεξε και τελείωσε πιο γρήγορα, αλλά το gem5 έτρεξε για περισσότερη ώρα συνολικά.

#### c. Αλλάξτε μια παράμετρο του επεξεργαστή και παρατηρήστε τα αποτελέσματα για τα δύο διαφορετικά CPU models. Δοκιμάστε να αλλάξετε την συχνότητα λειτουργίας και τη τεχνολογία της μνήμης που χρησιμοποιείτε. Παραθέστε και δικαιολογήσετε τα αποτελέσματα που παρατηρήσατε.

- Frequency:
  - minorCPU
    - 1Ghz:
      - simSeconds: 0.000353  
      - hostSeconds: 0.63
      - simInsts: 225221
    - 4GHZ
      - simSeconds: 0.000138
      - hostSeconds: 0.63
      - simInsts: 225221
    - 10kHz
      - simSeconds: 2.957730
      - hostSeconds: 8.79
      - simInsts: 225221

  - timingCPU
    - 1Ghz:
      - simSeconds: 0.000675
      - hostSeconds: 0.20
      - simInsts: 225204
    - 4GHZ
      - simSeconds: 0.000205
      - hostSeconds: 0.19
      - simInsts: 225204
    - 10kHz
      - simSeconds: 62.800400
      - hostSeconds: 89.18
      - simInsts: 225204

Παρατηρούμε ότι με αύξηση της συχνότητας μειώνεται ο χρόνος `simSeconds` ενώ το `hostSeconds` μένει ίδιο για ένα μεγάλο ευρος συχνοτήτων, για πολύ μικρές συχνότητες μεγαλώνει.
Τα `simInsts` μένει σταθερό ανεξαρτήτως της συχνότητας.
Τα αποτελέσματα είναι λογικά, αφού όταν η συχνότητα είναι μεγαλύτερη μία εντολή θα διαρκεί λιγότερο.

- Μνήμη:
  - minorCPU
    - DDR3_2133_8x8:
      - simSeconds: 0.000207  
      - simTicks: 207399000
      - hostSeconds: 0.67
    - DDR4_2400_8x8:
      - simSeconds: 0.000207
      - simTicks: 207319000
      - hostSeconds: 0.62

  - timingCPU
    - DDR3_2133_8x8:
      - simSeconds: 0.000360  
      - simTicks: 359925000
      - hostSeconds: 0.20
    - DDR4_2400_8x8:
      - simSeconds: 0.000361
      - simTicks: 360991000
      - hostSeconds: 0.19
    
Ο λόγος που το `simSeconds` ειναι ιδιο αναμεσα στην DDR3 και DDR4 ειναι οτι το προγραμμα έχει πολυ μικρο cache miss rate (`system.cpu.dcache.overallMshrMissRate::total`=`0.003229`). ~~Παρολα αυτα μπορουμε να δουμε απο το `simTicks` ότι η DDR4 είναι πιο γρήγορη.~~
    
##### Sources
- [https://www.gem5.org/documentation/general_docs/cpu_models/](https://www.gem5.org/documentation/general_docs/cpu_models)
- [https://www.gem5.org/documentation/general_docs/memory_system/index.html#access-types](https://www.gem5.org/documentation/general_docs/memory_system/index.html#access-types)
- [https://stackoverflow.com/questions/53085048/how-to-compile-and-run-an-executable-in-gem5-syscall-emulation-mode-with-se-py/53085049?fbclid=IwAR2B1Ndb3JZCdUGAYdJu5f_TdgsQ49aBjg_Uevr5zfuk-jJsN3KApGAo0dc#53085049](https://stackoverflow.com/questions/53085048/how-to-compile-and-run-an-executable-in-gem5-syscall-emulation-mode-with-se-py/53085049?fbclid=IwAR2B1Ndb3JZCdUGAYdJu5f_TdgsQ49aBjg_Uevr5zfuk-jJsN3KApGAo0dc#53085049)
