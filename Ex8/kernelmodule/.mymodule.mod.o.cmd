cmd_/home/student/Gruppe02/Sanntidssystemer/Ex8/kernelmodule/mymodule.mod.o := /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/staging/usr/bin/avr32-linux-gcc -Wp,-MD,/home/student/Gruppe02/Sanntidssystemer/Ex8/kernelmodule/.mymodule.mod.o.d  -nostdinc -isystem /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/staging/usr/bin-ccache/../lib/gcc/avr32-unknown-linux-uclibc/4.2.4/include -I/home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include -Iinclude  -include include/generated/autoconf.h -D__KERNEL__ -I/home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/mach-at32ap/include -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -Os -pipe -fno-builtin -mno-pic -march=ap -fno-stack-protector -fno-omit-frame-pointer -fno-optimize-sibling-calls -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow  -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(mymodule.mod)"  -D"KBUILD_MODNAME=KBUILD_STR(mymodule)"  -DMODULE -mno-relax -c -o /home/student/Gruppe02/Sanntidssystemer/Ex8/kernelmodule/mymodule.mod.o /home/student/Gruppe02/Sanntidssystemer/Ex8/kernelmodule/mymodule.mod.c

deps_/home/student/Gruppe02/Sanntidssystemer/Ex8/kernelmodule/mymodule.mod.o := \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/kernelmodule/mymodule.mod.c \
    $(wildcard include/config/module/unload.h) \
  include/linux/module.h \
    $(wildcard include/config/symbol/prefix.h) \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/unused/symbols.h) \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/kallsyms.h) \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/tracepoints.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/event/tracing.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
    $(wildcard include/config/constructors.h) \
    $(wildcard include/config/sysfs.h) \
  include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  include/linux/stddef.h \
  include/linux/compiler.h \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  include/linux/compiler-gcc4.h \
  include/linux/poison.h \
    $(wildcard include/config/illegal/pointer/value.h) \
  include/linux/prefetch.h \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/types.h \
  include/asm-generic/int-ll64.h \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/bitsperlong.h \
  include/asm-generic/bitsperlong.h \
  include/linux/posix_types.h \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/posix_types.h \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/processor.h \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/page.h \
    $(wildcard include/config/need/multiple/nodes.h) \
    $(wildcard include/config/phys/offset.h) \
  include/linux/const.h \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/addrspace.h \
    $(wildcard include/config/mmu.h) \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/cache.h \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/system.h \
    $(wildcard include/config/ownership/trace.h) \
  include/linux/linkage.h \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/linkage.h \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/ptrace.h \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/ocd.h \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/sysreg.h \
  include/linux/irqflags.h \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
  include/linux/typecheck.h \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/irqflags.h \
  include/asm-generic/cmpxchg-local.h \
  include/linux/stat.h \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/stat.h \
  include/linux/time.h \
    $(wildcard include/config/arch/uses/gettimeoffset.h) \
  include/linux/cache.h \
    $(wildcard include/config/arch/has/cache/line/size.h) \
  include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/spinlock/sleep.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
    $(wildcard include/config/ring/buffer.h) \
    $(wildcard include/config/numa.h) \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/staging/usr/bin-ccache/../lib/gcc/avr32-unknown-linux-uclibc/4.2.4/include/stdarg.h \
  include/linux/bitops.h \
    $(wildcard include/config/generic/find/first/bit.h) \
    $(wildcard include/config/generic/find/last/bit.h) \
    $(wildcard include/config/generic/find/next/bit.h) \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/bitops.h \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/byteorder.h \
  include/linux/byteorder/big_endian.h \
  include/linux/swab.h \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/swab.h \
  include/linux/byteorder/generic.h \
  include/asm-generic/bitops/non-atomic.h \
  include/asm-generic/bitops/fls64.h \
  include/asm-generic/bitops/sched.h \
  include/asm-generic/bitops/hweight.h \
  include/asm-generic/bitops/arch_hweight.h \
  include/asm-generic/bitops/const_hweight.h \
  include/asm-generic/bitops/lock.h \
  include/asm-generic/bitops/ext2-non-atomic.h \
  include/asm-generic/bitops/le.h \
  include/asm-generic/bitops/ext2-atomic.h \
  include/asm-generic/bitops/minix-le.h \
  include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  include/linux/dynamic_debug.h \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/debug/bugverbose.h) \
  include/asm-generic/bug.h \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/div64.h \
  include/asm-generic/div64.h \
  include/linux/seqlock.h \
  include/linux/spinlock.h \
    $(wildcard include/config/debug/spinlock.h) \
    $(wildcard include/config/generic/lockbreak.h) \
    $(wildcard include/config/preempt.h) \
    $(wildcard include/config/debug/lock/alloc.h) \
  include/linux/preempt.h \
    $(wildcard include/config/debug/preempt.h) \
    $(wildcard include/config/preempt/notifiers.h) \
  include/linux/thread_info.h \
    $(wildcard include/config/compat.h) \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/thread_info.h \
  include/linux/stringify.h \
  include/linux/bottom_half.h \
  include/linux/spinlock_types.h \
  include/linux/spinlock_types_up.h \
  include/linux/lockdep.h \
    $(wildcard include/config/lockdep.h) \
    $(wildcard include/config/lock/stat.h) \
    $(wildcard include/config/generic/hardirqs.h) \
    $(wildcard include/config/prove/rcu.h) \
  include/linux/rwlock_types.h \
  include/linux/spinlock_up.h \
  include/linux/rwlock.h \
  include/linux/spinlock_api_up.h \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/atomic.h \
  include/asm-generic/atomic-long.h \
  include/linux/math64.h \
  include/linux/kmod.h \
  include/linux/gfp.h \
    $(wildcard include/config/kmemcheck.h) \
    $(wildcard include/config/highmem.h) \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/zone/dma32.h) \
    $(wildcard include/config/debug/vm.h) \
  include/linux/mmzone.h \
    $(wildcard include/config/force/max/zoneorder.h) \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/sparsemem.h) \
    $(wildcard include/config/compaction.h) \
    $(wildcard include/config/arch/populates/node/map.h) \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/flat/node/mem/map.h) \
    $(wildcard include/config/cgroup/mem/res/ctlr.h) \
    $(wildcard include/config/no/bootmem.h) \
    $(wildcard include/config/have/memory/present.h) \
    $(wildcard include/config/have/memoryless/nodes.h) \
    $(wildcard include/config/need/node/memmap/size.h) \
    $(wildcard include/config/have/arch/early/pfn/to/nid.h) \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/sparsemem/extreme.h) \
    $(wildcard include/config/nodes/span/other/nodes.h) \
    $(wildcard include/config/holes/in/zone.h) \
    $(wildcard include/config/arch/has/holes/memorymodel.h) \
  include/linux/wait.h \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/current.h \
  include/linux/threads.h \
    $(wildcard include/config/nr/cpus.h) \
    $(wildcard include/config/base/small.h) \
  include/linux/numa.h \
    $(wildcard include/config/nodes/shift.h) \
  include/linux/init.h \
    $(wildcard include/config/hotplug.h) \
  include/linux/nodemask.h \
  include/linux/bitmap.h \
  include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/string.h \
  include/linux/pageblock-flags.h \
    $(wildcard include/config/hugetlb/page.h) \
    $(wildcard include/config/hugetlb/page/size/variable.h) \
  include/generated/bounds.h \
  include/linux/memory_hotplug.h \
    $(wildcard include/config/have/arch/nodedata/extension.h) \
    $(wildcard include/config/sparsemem/vmemmap.h) \
    $(wildcard include/config/memory/hotremove.h) \
  include/linux/notifier.h \
  include/linux/errno.h \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/errno.h \
  include/asm-generic/errno.h \
  include/asm-generic/errno-base.h \
  include/linux/mutex.h \
    $(wildcard include/config/debug/mutexes.h) \
  include/linux/rwsem.h \
    $(wildcard include/config/rwsem/generic/spinlock.h) \
  include/linux/rwsem-spinlock.h \
  include/linux/srcu.h \
  include/linux/topology.h \
    $(wildcard include/config/sched/smt.h) \
    $(wildcard include/config/sched/mc.h) \
    $(wildcard include/config/use/percpu/numa/node/id.h) \
  include/linux/cpumask.h \
    $(wildcard include/config/cpumask/offstack.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/debug/per/cpu/maps.h) \
    $(wildcard include/config/disable/obsolete/cpumask/functions.h) \
  include/linux/smp.h \
    $(wildcard include/config/use/generic/smp/helpers.h) \
  include/linux/percpu.h \
    $(wildcard include/config/need/per/cpu/embed/first/chunk.h) \
    $(wildcard include/config/need/per/cpu/page/first/chunk.h) \
    $(wildcard include/config/have/setup/per/cpu/area.h) \
  include/linux/pfn.h \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/percpu.h \
  include/asm-generic/percpu.h \
  include/linux/percpu-defs.h \
    $(wildcard include/config/debug/force/weak/per/cpu.h) \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/topology.h \
  include/asm-generic/topology.h \
  include/linux/mmdebug.h \
    $(wildcard include/config/debug/virtual.h) \
  include/linux/workqueue.h \
    $(wildcard include/config/debug/objects/work.h) \
  include/linux/timer.h \
    $(wildcard include/config/timer/stats.h) \
    $(wildcard include/config/debug/objects/timers.h) \
  include/linux/ktime.h \
    $(wildcard include/config/ktime/scalar.h) \
  include/linux/jiffies.h \
  include/linux/timex.h \
  include/linux/param.h \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/param.h \
    $(wildcard include/config/hz.h) \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/timex.h \
  include/linux/debugobjects.h \
    $(wildcard include/config/debug/objects.h) \
    $(wildcard include/config/debug/objects/free.h) \
  include/linux/elf.h \
  include/linux/elf-em.h \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/elf.h \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/user.h \
  include/linux/kobject.h \
  include/linux/sysfs.h \
  include/linux/kref.h \
  include/linux/moduleparam.h \
    $(wildcard include/config/alpha.h) \
    $(wildcard include/config/ia64.h) \
    $(wildcard include/config/ppc64.h) \
  include/linux/tracepoint.h \
  include/linux/rcupdate.h \
    $(wildcard include/config/rcu/torture/test.h) \
    $(wildcard include/config/tree/rcu.h) \
    $(wildcard include/config/tree/preempt/rcu.h) \
    $(wildcard include/config/tiny/rcu.h) \
  include/linux/completion.h \
  include/linux/rcutree.h \
    $(wildcard include/config/no/hz.h) \
  /home/student/Gruppe02/Sanntidssystemer/Ex8/buildroot/buildroot-avr32-v3.0.0_TTK4147/output/build/linux-2.6.35.4/arch/avr32/include/asm/module.h \
  include/trace/events/module.h \
  include/trace/define_trace.h \
  include/linux/vermagic.h \
  include/generated/utsrelease.h \

/home/student/Gruppe02/Sanntidssystemer/Ex8/kernelmodule/mymodule.mod.o: $(deps_/home/student/Gruppe02/Sanntidssystemer/Ex8/kernelmodule/mymodule.mod.o)

$(deps_/home/student/Gruppe02/Sanntidssystemer/Ex8/kernelmodule/mymodule.mod.o):
