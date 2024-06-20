use std::time::Instant;

fn main() {
    let start = Instant::now();
    for seed in 1u64..=100_000_000u64 {
        let result = collatz(seed);
        if seed % 1_000_000 == 0 {
            println!("Seed: {} Steps: {}", seed, result);
        }
    }
    let end = Instant::now();
    println!(
        "Rust Took {} s",
        (end.duration_since(start).as_millis() as f64) / 1000.0f64
    );
}

fn collatz(mut seed: u64) -> u64 {
    let mut cnt = 0;

    while seed > 1 {
        cnt += 1;
        if seed % 2 == 0 {
            seed /= 2;
        } else {
            seed = (seed * 3) + 1;
        }
    }

    cnt
}
