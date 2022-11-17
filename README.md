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


2. Εκτός από το αρχείο εξόδου stats.txt που παράγεται στο τέλος της εξομοίωσης, ο gem5 παράγει
και τα αρχεία config.ini και config.json. Τα αρχεία αυτά παρέχουν πληροφορίες για το σύστημα
που εξομοιώνει ο gem5.

a. Χρησιμοποιήστε τα αρχεία αυτά για να επαληθεύσετε την απάντηση σας στο πρώτο
ερώτημα. Παραθέστε τα σχετικά πεδία.

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

## b. Τι είναι τα sim_seconds, sim_insts και host_inst_rate?

- **sim_seconds**: Number of seconds simulated.
- **sim_insts**: Number of instructions simulated.
- **host_inst_rate**: Simulator instruction rate (inst/s).

## c. Ποιό είναι το συνολικό νούμερο των «committed» εντολών? Γιατί δεν είναι ίδιο το νούμερο με αυτό που παρουσιάζεται από στατιστικά που παρουσιάζονται από τον gem5?

Δεν είμαστε σίγουροι αν θέλει τα committed instructions ή committed operations

- Τα instructions committed είναι 5028 
- Τα operations committed είναι 5834
- simInsts 5028

### 3. Εκτός από τις πληροφορίες που παρέχονται σε αυτήν την άσκηση, είναι σημαντικό να μπορείτε να ανατρέχετε και να αναζητάτε πληροφορίες στη βιβλιογραφία. Έτσι χρησιμοποιώντας ως αρχή το site του gem5 (gem5.org) αναζητήστε πληροφορίες για τα διαφορετικά μοντέλα in-order CPUs που χρησιμοποιεί ο gem5 (hint: στο παράδειγμα χρησιμοποιήσατε το μοντέλο CPU: minor) και παραθέστε μια συνοπτική παράγραφο για καθένα από αυτά.

Τα μοντέλα CPU που υπάρχουν στον gem5 είναι **AtomicSimpleCPU**, **TimingSimpleCPU**, **O3CPU**, **MinorCPU** και **KvmCPU**.

- SimpleCPU
  - **AtomicSimpleCPU**: Χρησιμοποιεί atomic προσβαση στην μνήμη
  - **TimingSimpleCPU**:

- **O3CPU**:
- **MinorCPU**:
- **KvmCPU**:

a.
