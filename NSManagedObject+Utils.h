//
//  NSManagedObject+Utils.h
//
//  Created by Aaron Voisine on 8/22/13.
//  Copyright (c) 2013 Aaron Voisine <voisine@gmail.com>
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#import <CoreData/CoreData.h>

@interface NSManagedObject (Utils)

// create objects
+ (instancetype)managedObject;
+ (NSArray *)managedObjectArrayWithLength:(NSUInteger)length;

// fetch existing objects
+ (NSArray *)allObjects;
+ (NSArray *)objectsMatching:(NSString *)predicateFormat, ...;
+ (NSArray *)objectsMatching:(NSString *)predicateFormat arguments:(va_list)args;
+ (NSArray *)objectsSortedBy:(NSString *)key ascending:(BOOL)ascending;
+ (NSArray *)objectsSortedBy:(NSString *)key ascending:(BOOL)ascending offset:(NSUInteger)offset limit:(NSUInteger)lim;
+ (NSArray *)fetchObjects:(NSFetchRequest *)request;

// count existing objects
+ (NSUInteger)countAllObjects;
+ (NSUInteger)countObjectsMatching:(NSString *)predicateFormat, ...;
+ (NSUInteger)countObjectsMatching:(NSString *)predicateFormat arguments:(va_list)args;
+ (NSUInteger)countObjects:(NSFetchRequest *)request;

// delete objects
+ (NSUInteger)deleteObjects:(NSArray *)objects;

// call this before any NSManagedObject+Utils methods to use a concurrency type other than NSMainQueueConcurrencyType
+ (void)setConcurrencyType:(NSManagedObjectContextConcurrencyType)type;

// set the fetchBatchSize to use when fetching objects, default is 100
+ (void)setFetchBatchSize:(NSUInteger)fetchBatchSize;

// Returns the managed object context for the application. If the context doesn't already exist,
// it is created and bound to the persistent store coordinator for the application.
+ (NSManagedObjectContext *)context;

+ (void)saveContext;

+ (NSString *)entityName;
+ (NSFetchRequest *)fetchRequest;
+ (NSFetchedResultsController *)fetchedResultsController:(NSFetchRequest *)request;

- (void)deleteObject;
- (id)get:(NSString *)key; // thread safe valueForKey:
- (void)set:(NSString *)key to:(id)value; // thread safe setValue:forKey:

@end
